#include "Fondjeu.hpp"

Fondjeu::Fondjeu():

        pixmap_fondjeu(new QPixmap),
        coor1({0,0}),
        coor2({0,0})
{
     pixmap_fondjeu->load("./image_code/etoiles.jpg"); //chargement de l'image de fond
}

/** foncion qui nous permet de gérer le mouvement de l'image de fond de notre jeu en sla translatant vers le bas
 * d'une certaine hauteur */
void Fondjeu:: mvt_font(float const hauteur)
{
        if (this->coor1.y+2>hauteur){
            this->coor1.y=0;
            this->coor2.y=-hauteur;

        }
        else {

            this->coor1.y+=2;
            this->coor2.y=coor1.y-hauteur;
        }
    }

//nous devons gérer tout le fond de notre fenêtre, pour une plus simple utilisation
//nous allons créer des get et des set
vec2 Fondjeu::getCord_jeu() const
{
    return coor1;
}

vec2 Fondjeu::getCord_jeu1() const
{
    return coor2;
}

QPixmap *Fondjeu::getPimax_jeu() const
{
    return pixmap_fondjeu;
}
