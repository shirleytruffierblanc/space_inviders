#pragma once
#ifndef FONDJEU_HPP
#define FONDJEU_HPP
#include <QPixmap>
#include "vec2.hpp"

/** nous avons crée une classe nous permettant de gérer le jeu pour une meilleur
 * lisibilit du code*/

class Fondjeu
{
public:
    Fondjeu();

    /** fonction qui gère le mouvement du fond, la photo qui bouge à l'infini,
        nous devons en créer deux d'où la présence de deux get*/
    void mvt_font(float const hauteur);

    vec2 getCord_jeu() const;//image 1
    vec2 getCord_jeu1() const; //image donc créant l'impression de défilement infini
    QPixmap *getPimax_jeu() const;


private:

    /** déclaration des différents Qpixmap qui nous permetten de gérer l'image de fond de notre jeu*/
    QPixmap *pixmap_fondjeu;
    /** déclaration des coordonnées*/
    vec2 coor1;//déclaration des coordonnées du fond
    vec2 coor2;//déclaration des coordonnées du fond
};

#endif // FONDJEU_HPP
