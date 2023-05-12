#include "joueur.hpp"
#include "Comportement.hpp"
#include "vec2.hpp"

joueur::joueur()
    : Comportement(0,0),tir_laser_flag(false),pixmap_joueur(new QPixmap)
{
        pixmap_joueur->load("./image_code/joueur.xcf");
}

joueur::joueur(vec2 const& center_param)
    :Comportement(center_param.x,center_param.y),tir_laser_flag(false),pixmap_joueur(new QPixmap)
{
        pixmap_joueur->load("./image_code/joueur.xcf");
}

/** Initialisation des coordonnées du tir du joueur*/
vec2 joueur::tir_laser(){
    vec2 p=this->center;
    vec2 centretir={p.x,p.y};
    return centretir;
}

//on initialise le pixmap de notre vaiseau pour faire appel correctement à notre image du vaisseau
QPixmap *joueur::getPixmap_joueur() const
{
    return pixmap_joueur;
}

void joueur::setTir_laser_flag(bool value)
{
    tir_laser_flag = value; // on rentre une valeur d'entrée afin de pouvoir iniialiser le ti de départ'
}

bool joueur::getTir_laser_flag() const
{
    return tir_laser_flag;
}
/** nous allons gérer la vie avec get et set pour aller chercher les valeurs au départ pour plus de
facilité et compréhension du code*/
void joueur::setJoueur_vie(int value)
{
    vie_joueur = value;
}

int joueur::getJoueur_vie() const
{
    return vie_joueur;
}


