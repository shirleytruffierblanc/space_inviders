#include "circle.hpp"
#include "joueur.hpp"
#include "Comportement.hpp"
#include <cmath>


circle::circle()
    : Comportement(0,5),speed(2.0f,2.0f)
{}

circle::circle(vec2 const& center_param,vec2 const& speed_param, int num_param)
    :Comportement(center_param.x,center_param.y),speed(speed_param),num_pixmap(num_param)
{}


/** j'ai donc préféré gérer le déplacement des différents ennemis directement dans leur classe
 * comme il était conseillé car ils ont en effet tous le même comportement
*/
vec2 circle::deplacement(float const w, float const h,vec2 vitesse_debut){

    vec2 new_speed=this->speed;
    vec2& p=this->center;

    float const m = 60;

    //gestion de la collision avec le côté droit de la fenêtre
    if( p.x+m>w )
    {
        p.x=w-m;
        new_speed.x=-this->speed.x;
    }

    //gestion de la collision avec le côté gauche de la fenêtre
    if( p.x<0 )
    {
        p.x=0;
        new_speed.x=-this->speed.x;
    }

    //si l'ennemi sort de la fenêtre il disparaît
    if (p.y>h){
        p.y=0;
        p.x=rand()%((int)w);
        new_speed=vitesse_debut;

    }
    return new_speed; //on retourne la valeur de l'ennemi car d autres apparaissent en permanence
}

//nous gérons la colision de l'ennemi et du joueur et un autre ennemi apprait en haut de l'écran
int circle::collision_ennemi(joueur joueur, float const w, int num_param)
{
    int vie_N=joueur.getJoueur_vie();

    vec2 centre_joueur=joueur.getCenter();
    float x_joueur=centre_joueur.x;
    float y_joueur=centre_joueur.y;
    float x_vaisseau=this->center.x;
    float y_vaisseau=this->center.y;


//collision si un des bord de l'ennemi se trouve dans l'image du joueur
    if (((((x_joueur<=x_vaisseau)&&(x_vaisseau<=x_joueur+70))&&((y_joueur+0<=y_vaisseau)&&(y_vaisseau<=y_joueur+10)))||(((x_joueur<=x_vaisseau)&&(x_vaisseau<=x_joueur+70))&&((y_joueur+0<=y_vaisseau+60)&&(y_vaisseau+60<=y_joueur+10))))||((((x_joueur<=x_vaisseau+60)&&(x_vaisseau+60<=x_joueur+70))&&((y_joueur+0<=y_vaisseau)&&(y_vaisseau<=y_joueur+10)))||(((x_joueur<=x_vaisseau+60)&&(x_vaisseau+60<=x_joueur+70))&&((y_joueur+0<=y_vaisseau+60)&&(y_vaisseau+60<=y_joueur+10)))))
    {
        //s'il y a collision : l'ennemi réapparait sur la ligne du haut avec une position y aléatoire avec image aléatoire
        this->center.y=0;
        this->center.x=rand()%((int)w);
        this ->num_pixmap=num_param;

        vie_N-=1;//perte d'une vie du joueur on décrémente le compteur vie
    }

    return vie_N;
}

/** grâce aux get et set on va gerer les différentes vitesses de notre ennemi*/
vec2 circle::getSpeed() const
{
    return speed;
}

void circle::setSpeed(const vec2 &value)
{
    speed = value;
}

int circle::getNum() const
{
    return num_pixmap;
}

void circle::setNum(int value)
{
    num_pixmap = value;
}
