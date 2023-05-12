

#pragma once

#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <QPixmap>
#include <iostream>

#include "vec2.hpp"
#include "Comportement.hpp"

class joueur : public Comportement  //nous avons finalement utilisé un héritage pour plus de facilité
                                      //dans le comportement de nos différents éléments
                                    //notre première solution était trop compliqué à gérer niveau code
{
public:
    /** Constructeur vaisseau 0,0*/
    joueur();
    /** Constructeur vaisseau en x,y*/
    joueur(vec2 const& center_param);

    /** Initialisation des coordonnées du tir aux coordonnée du vaisseau*/
    vec2 tir_laser();

    /** déclaration de mon pixmap de mon joueur me permettant de faire afficher la
     * soucoupe après sur l'écran*/
    QPixmap *getPixmap_joueur() const;

    /** déclaration des get et set des tirs de mon joueur */
     bool getTir_laser_flag() const;
     void setTir_laser_flag(bool value);

    /** gestion des get et set de la classe joueur, déclaré en public car on va les utiliser dans
     * le code principal correspondant au render area, ils gèrent le calcul de la vie*/
     int getJoueur_vie() const;
     void setJoueur_vie(int value);



private :
    /** Qpixmap pour l'image du vaisseau spatial*/
    QPixmap *pixmap_joueur;
    /** gère le tir laser*/
    bool tir_laser_flag;
    /** initialisation de la vie*/
    int vie_joueur;
};

#endif
