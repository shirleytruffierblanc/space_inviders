#pragma once

#ifndef COMPORTEMENT_HPP
#define COMPORTEMENT_HPP

#include "vec2.hpp"


/** mère permettant de construire le joueur et les différents ennemis
    car ils sont composés d'objets similaires*/
class Comportement
{
public:
    /** Constructeur d'un comportement */
    Comportement();
    /** Constructeur du comportement initial d'un des objets soient le joueur soit l'ennemi */
    Comportement(int p_x, int p_y);

    /** coordonnées du déplacement des futurs objets*/
    void deplacement_objet(int parametre_x, int parametre_y);

    /** declaration des différents get et set */
    vec2 getCenter() const;
    void setCenter(const vec2 &value);

protected:
    vec2 center;


};

#endif

