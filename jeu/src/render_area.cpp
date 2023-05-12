
#include "render_area.hpp"
#include "joueur.hpp"
#include "vaisseau.hpp"
#include "Comportement.hpp"
#include "circle.hpp"

#include <QPainter>
#include <QTime>
#include <QPixmap>
#include <QMouseEvent>
#include <QLabel>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <math.h>

/** initialisation des différentes variable dont nous avons besoin dans
 * le render_area*/
render_area::render_area(QWidget *parent)
    :QWidget(parent),
      flag_fin_du_jeu(false), //on termine la partie
      debut_mvt(false),
      pixmap_laser(new QPixmap),
      debut_jeu(false),
      flagE(true),
      show_area(false),
      barre_joueur(vec2(120,300)), //on lui assigne une taille pour plus de faclité
      coordonnees_tir({0,0}), //nous devons les initialiser à zéro pour qu'il soit au niveau du joueur
      vitesse_init({4.0f,4.0f}),
      cpt(0),
      timer(),
      nbalien_bleu(0),
      nbalien_gris(0)


{
    emit vie_generale(nb_vietotale);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    connect(&timer, SIGNAL(timeout()), this, SLOT(update_timer()));
    timer.setSingleShot(false);
    timer.start(30); //every 30ms

    //téléchargement des différentes images de nos différents objets
    pixmap_laser->load("./image_code/laser.xcf"); //moyen de tuer les ennemis

    //chargement des deux ennemis, on est obligé de créer un nouveau pixmap car sinon ca ne marche pas
    QPixmap *pixmap_ennemis = new QPixmap; //création du nouveau pixmap
    pixmap_ennemis->load("./image_code/alien_gris.xcf");
    v_ennemis.push_back(*pixmap_ennemis);
    pixmap_ennemis->load("./image_code/alien_bleu.xcf");
    v_ennemis.push_back(*pixmap_ennemis);
    //nous devons donc créé des ennemis aléatoirement et le mettre a la suite dans la liste de vecteur
    vaisseauennemi.push_back(circle(vec2(200,0),vitesse_init,rand()%(v_ennemis.size())));
    barre_joueur.setJoueur_vie(3);

}



//cette fonction nous permet de lancer le jeu, et le premier laser du joueur, initialisation de notre jeu
render_area::~render_area()
{
    if(pixmap_laser!=nullptr)
    {
        delete pixmap_laser;
        pixmap_laser=nullptr;
    }
}

//nous permet de gérer l'affichage des différents composant sur l'inerface graphique
void render_area::paintEvent(QPaintEvent*)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen;
    pen.setWidth(1.0);
    pen.setColor(Qt::red);
    painter.setPen(pen);

    QBrush brush = painter.brush();
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    if (flag_fin_du_jeu==false)
        {
        QPixmap *pixmap_fondjeu = fond_infini.getPimax_jeu();
        painter.drawPixmap(fond_infini.getCord_jeu().x,fond_infini.getCord_jeu().y,width(),height(), *pixmap_fondjeu);
        painter.drawPixmap(fond_infini.getCord_jeu1().x,fond_infini.getCord_jeu1().y,width(),height(), *pixmap_fondjeu);
        vec2 centrej=barre_joueur.getCenter();
        QPixmap *pixmap_joueur = barre_joueur.getPixmap_joueur();
        painter.drawPixmap(centrej.x,centrej.y,70,120, *pixmap_joueur);
        if(flag_fin_du_jeu==false)
        {
        for (unsigned int i=0;i<vaisseauennemi.size();i++)
        {
            vec2 cennemi=vaisseauennemi[i].getCenter();
             int nb = vaisseauennemi[i].getNum();
        painter.drawPixmap(cennemi.x,cennemi.y,60,60, v_ennemis[nb]);
        }
        }
        if (barre_joueur.getTir_laser_flag()==true){
            painter.drawPixmap(coordonnees_tir.x,coordonnees_tir.y,30,30, *pixmap_laser);
        }
        }

}


void render_area::update_timer()
{
//nous devons gérer le timer de façon permanente pour pouvoir ensuite gérer correctement
//le déplacement de tous nos différents objets : joueur et ennemis
    if (debut_mvt==true) {
        debut_jeu=true;
        fond_infini.mvt_font(height());
        deplacement_enV();
        cpt+=1;

        /** gestion du tir*/
        if (barre_joueur.getTir_laser_flag()==true){
        deplacement_laser(coordonnees_tir,nbalien_gris,nbalien_bleu);

    }

        if (cpt==60) //le temps correspondant à l'apparition des aliens au fur et à mesure
    {
        vitesse_init.x*=-1.00;
        vitesse_init.y*=1.00;
        cpt=0; //on l'initialise à zéro pour pouvoir renvoyer des ennemis au fur et à mesure
        vaisseauennemi.push_back(circle(vec2(rand()%(width()),0),vitesse_init,rand()%(v_ennemis.size())));
        for (auto& value : vaisseauennemi){
            vec2 v = value.getSpeed();
            double v_x = v.x*1.03;
            float v_x_f= (float)v_x;
            double v_y= v.y*1.03;
            float v_y_f=(float)v_y;
            value.setSpeed({v_x_f,v_y_f});
        }
    }
        repaint(); //affichage des différents lasers de notre joueur
   }
}


//gère le déplacement aléatoire des différents ennemis
void render_area::deplacement_enV()
{
    for (unsigned int i=0; i<vaisseauennemi.size();i++)
    {
    vec2 p=vaisseauennemi[i].getCenter();
    vec2 s=vaisseauennemi[i].getSpeed();
    vaisseauennemi[i].setCenter({p.x+s.x, p.y+s.y});
    vaisseauennemi[i].setSpeed(collision_desennemis(i));
    }
}

//déplacement du laser du joueur
void render_area::deplacement_laser(vec2& coordonnees_tir, int& nbalien_bleu, int& nbalien_vert)
{

    coordonnees_tir.y=coordonnees_tir.y-20;
    if (coordonnees_tir.y<0){
       barre_joueur.setTir_laser_flag(false);
    }
    std::vector<int> sup(0);
    for (unsigned int i=0;i<vaisseauennemi.size();i++)
    {

    vec2 p=vaisseauennemi[i].getCenter();
    float x_vaisseau_ennemi=p.x;
    float y_vaisseau_ennemi=p.y;
    float x_tir=coordonnees_tir.x;
    float y_tir=coordonnees_tir.y;


    if (((((x_vaisseau_ennemi<=x_tir)&&(x_tir<=x_vaisseau_ennemi+60))&&((y_vaisseau_ennemi<=y_tir)&&(y_tir<=y_vaisseau_ennemi+60)))||(((x_vaisseau_ennemi<=x_tir)&&(x_tir<=x_vaisseau_ennemi+60))&&((y_vaisseau_ennemi<=y_tir+30)&&(y_tir+30<=y_vaisseau_ennemi+60))))||((((x_vaisseau_ennemi<=x_tir+30)&&(x_tir+30<=x_vaisseau_ennemi+60))&&((y_vaisseau_ennemi<=y_tir)&&(y_tir<=y_vaisseau_ennemi+60)))||(((x_vaisseau_ennemi<=x_tir+30)&&(x_tir+30<=x_vaisseau_ennemi+60))&&((y_vaisseau_ennemi<=y_tir+30)&&(y_tir+30<=y_vaisseau_ennemi+60)))))
    {
     int tir_aleatoire = rand()%(width());
    float choix_aleatoire = (float) tir_aleatoire;
    vaisseauennemi[i].setCenter({choix_aleatoire,20});


        int nb = vaisseauennemi[i].getNum();
        switch(nb){
            case 0 :
                nbalien_bleu+=1;
                break;
            case 1 :
                nbalien_gris+=1;
                break;
        }

    vaisseauennemi[i].setNum(rand()%(v_ennemis.size()));
    barre_joueur.setTir_laser_flag(false);
    sup.push_back(i);
    score_joueur+=15;
    emit updatescorejoueur(score_joueur);
    emit updatealien(nbalien_bleu,nbalien_gris);
    }
    }
    for (int i=sup.size()-1;i>=0;i--)
    {
        vaisseauennemi.erase(vaisseauennemi.begin()+sup[i]); //nous permet de supprimer les ennemis par la fin du vecteur créé
    }
}


    /** équivalent au collision_handling des codes du TP, mais
     * mais nous le renommons pour une meilleur compréhension
    * du code*/
vec2 render_area::collision_desennemis(unsigned int i)
{
    //définition de la taille de la fenêtre d'affichage pour l'image du jeu
    float const w = width();
    float const h = height();

    //gérer les rebond des ennemis contre la fenêtre
    vec2 nouvelle_vitesse = vaisseauennemi[i].deplacement(w,h,vitesse_init);

    //gerer la collision avec le vaisseau du joueur et les ennemies et la vie du joueur
    int vie_N = vaisseauennemi[i].collision_ennemi(barre_joueur, w,rand()%(v_ennemis.size())); //on gère la vie

    //gestion de la vie
    barre_joueur.setJoueur_vie(vie_N);
    int vie_objet=barre_joueur.getJoueur_vie();
    if (vie_objet>0)
    {
        emit vie_generale(vie_objet);
    }
    else
    {
        if (flagE==true)
        {
            flagE=false;
            loose();
        }
    }
    return nouvelle_vitesse;
}

//réinitialise le mouvement du vaisseau ennemis en permanence
void render_area::change_mvtvaisseau(){
    debut_mvt=!debut_mvt;
}

//gestion du mouvement du joueur avec les touches du clavier
void render_area::keyPressEvent(QKeyEvent *event)
{
    if (debut_mvt)
    {
    vec2 centrej=barre_joueur.getCenter();
    switch(event->key())
    {
        case Qt::Key_Left:
        if (centrej.x-10>=0)
        {
            barre_joueur.setCenter({centrej.x-10,centrej.y});
        }
            break;

        case Qt::Key_Right:
            if (centrej.x+70+10<=width())
            {
              barre_joueur.setCenter({centrej.x+10,centrej.y});
            }
            break;

        case Qt::Key_Down:
        if (centrej.y+10+120<=height())
        {
            barre_joueur.setCenter({centrej.x, centrej.y+10});

        }
        break;

    case Qt::Key_Up:
        if(centrej.y-10>=0)
        {
            barre_joueur.setCenter({centrej.x,centrej.y-10});
        }

        case Qt::Key_Space:

            if (barre_joueur.getTir_laser_flag()==false){
            barre_joueur.setTir_laser_flag(true);
            coordonnees_tir = barre_joueur.tir_laser();
            }
            break;

    }
    }
    repaint(); //remise à jour
}

//reprise du code du cours
void render_area::affichage_score_joueur(int& score_joueur){
    /** nous avons pris l'exemple du cours pour l'enregistrement du fichier
     * nous somme obligé d'écrire le score dans un fichier pour pouvoir l'écrire ensuite*/
    using namespace std;
    ofstream fichier_du_score("affichage_du_score.txt", ios::app);  //ouverture du fichier

    if(fichier_du_score)  //condition de l'ouverture du fichier
    {
        fichier_du_score << "Score -> "<<score_joueur ;

        fichier_du_score.close();  // fermeture du fichier
    }
    else
    {cout << "Errreur: impossible le fichier en lecture !" << endl;}


}

//fonction qui gère la défaite du joueur
void render_area::loose()
{
    debut_mvt=false;
    affichage_score_joueur(score_joueur);
    flagE=true;

}

