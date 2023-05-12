#pragma once

#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP

#include "circle.hpp"
#include "Comportement.hpp"
#include "joueur.hpp"
#include "Fondjeu.hpp"

#include <QPixmap>
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <list>

//forward declaration of QLabel
class QLabel;


class render_area : public QWidget
{
    Q_OBJECT
protected:
    /** Actual drawing function */
    void paintEvent(QPaintEvent *event);
public:

    render_area(QWidget *parent = 0);
    ~render_area();

    /** gère le mouvement du vaisseau*/
    void change_mvtvaisseau();

    /** nous devons gérer les coordonnées de notre laser*/
    void deplacement_laser(vec2& coordonnees_tir, int& nbalien_bleu, int& nbalien_vert);

    /** fonction qui nous permet de se déplacer avec les flèches du clavier, plus facile à
       gérer que le déplacement avec la souris pour le joueur et la gestion des tirs (j'ai changé par rapport à ce que
        j'avais commencé précédemment*/
    void keyPressEvent(QKeyEvent *event);

    /** fonction qui gère la perte de la partie*/
    void loose();

    /** mise à jour du score du joueur*/
    void affichage_score_joueur(int& score_joueur);

    /** fonction du déplacement aléatoire des différents ennemis*/
    void deplacement_enV();

private slots:

    /** Function called periodically at constant time interval by a timer */
    void update_timer();

private:
    /** vecteur contenant tous les ennemis */
    std::vector<circle> vaisseauennemi;

    /** Contient les images des différents ennemis */
    std::vector<QPixmap> v_ennemis;

    /** nous devons gérer l'ensemble des différents déplacements des ennemis */
    vec2 collision_desennemis(unsigned int i);
    void deplacement_ennemis();

    /** Move forward in time */
    void numerical_integration();

    /** déclaration des différents attributs*/
    float width_window;
    float height_window;


    /**  déclaration des différents booléens*/
    bool debut_mvt; //déclarer les différents états pour le mouvement du joueur*/
    bool debut_jeu; //début du jeu
    bool flag_fin_du_jeu;// si ce flag est à true alors c'est la fin du jeu
    bool flagE;
    bool show_area;

    /** déclaration de tous les entiers*/
    //gestion des différents aliens
    int nbalien_gris;// initialisation du nombre d'ennemis
    int nbalien_bleu;// initialisation du nombre d'ennemis
    int score_joueur; //permet d'afficher ensuite le score du joueur
    int nb_vietotale;// initialisation du nombre de vie du joueur
    int cpt; //permet une récurence des actions

    /** déclaration des vecteurs */
    vec2 coordonnees_tir; //coordonnées du tir de notre joueur
    vec2 vitesse_init; //vitesse initiale de déplacement
    vec2 coord_fond_jeu;//initialisation des coordonnées du fond


    QTimer timer; //timer de jeu
    QPixmap *pixmap_laser;//nous créeons un pixmap qui va nous permettre de gérer le tir laser du joueur

    /** création du vaisseau */
    joueur barre_joueur;

    /** utilisation d ela classe fond jeu nous permettant de dessiner le fond infini dans le render_area*/
    Fondjeu fond_infini;



/** déclaration des différents signaux que nous gérons avec l'interface graphique par la suite
 * c'est ce qu'il va apparaître sur l'écran de jeu*/
signals:
    /** Mise a jour du nombre de vie du joueur */
   void vie_generale(int nombre_de_vie);
   /** Mise a jour du score du joueur */
   void updatescorejoueur(int score);
   /** mise a jouer des différents aliens */
   void updatealien(int a, int b);


};

#endif
