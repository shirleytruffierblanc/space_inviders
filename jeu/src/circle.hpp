
#pragma once
#include <iostream>
#include <QPixmap>

#include "vec2.hpp"
#include "joueur.hpp"
#include "Comportement.hpp"


#ifndef CIRCLE_HPP
#define CIRCLE_HPP

//cette élément va donc correspondre aux ennemis de mon joueur, nous allons donc gérer toute la création
//des ennemis ici
/** A structure containing parameter of a geometric circle */
class circle : public Comportement
{
    /** radius coordinate */
public:

    /** Constructor circle (0,0) */
    circle();
    /** Constructor circle*/
    circle(vec2 const& center_param,vec2 const& speed_param, int num_param);

     /** declaration des différents get et set, nous permettant de contrôler
            la vitesse de nos ennemis*/
    vec2 getSpeed() const;
    void setSpeed(const vec2 &value);

    /** getter and setter numpixmap*/
    int getNum() const;
    void setNum(int value);

    /** déplacement de mon ennemi, avec les différentes variables*/
    vec2 deplacement(float const w, float const h, vec2 vitesse_debut);

    /** collision entre l'ennemi et le joueur on l'utilise également dans le render area*/
    int collision_ennemi(joueur joueur, float const w, int num_param);


private :
    /** vitesse de déplacement de l'ennemi */
    vec2 speed;
    /** image que l'on télécharge passée en paramètre correspondant à l'ennemi */
    int num_pixmap;


};



#endif
