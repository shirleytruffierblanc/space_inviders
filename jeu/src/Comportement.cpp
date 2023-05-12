#include "Comportement.hpp"
#include <iostream>

Comportement::Comportement()
    :center()
{}


Comportement::Comportement(int p_x, int p_y)
    :center(p_x,p_y)
{}


void Comportement::deplacement_objet(int parametre_x, int parametre_y){
    vec2& centrej=this->center;
    centrej.x+=parametre_x;
    centrej.y +=parametre_y;

}

void Comportement::setCenter(const vec2 &value)
{
    center = value;
}

vec2 Comportement::getCenter() const
{
    return center;
}
