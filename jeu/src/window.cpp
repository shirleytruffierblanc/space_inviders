
#include "window.hpp"

#include "render_area.hpp"
#include "ui_mainwindow.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


window::window(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::MainWindow),render(new render_area)
{
    ui->setupUi(this);
    ui->layout_scene->addWidget(render);
    render->setFocus();

    //nous permet de faire afficher la souris
    nombreVie = new QLabel();
    nombreVie->setText("Vie joueur : " +QString :: number(3));

    //à rajouter pour les points et les différents aliens
        point_joueur = new QLabel();
        point_joueur->setObjectName(QString::fromUtf8("nombreVie"));

        alien_bleu = new QLabel();
    alien_bleu->setObjectName(QString::fromUtf8("alien_bleu = "));

    alien_gris = new QLabel();
    alien_gris->setObjectName(QString::fromUtf8("alien_gris = "));

    //initialisation des Widgets
    ui->info->addWidget(nombreVie);
    ui->info->addWidget(point_joueur);
    ui->info->addWidget(alien_bleu);
    ui->info->addWidget(alien_gris);
    ui->info->addItem(new QSpacerItem(0,0,QSizePolicy::Minimum,QSizePolicy::Expanding));


    //Connection with signals
    connect(ui->quit,SIGNAL(clicked()),this,SLOT(action_quit()));
    connect(ui->start,SIGNAL(clicked()),this,SLOT(action_start()));
    connect(render,SIGNAL(updatescorejoueur(int)),this,SLOT(action_score(int)));
    connect(render,SIGNAL(updatealien(int, int)),this,SLOT(action_alien(int,int)));
    connect(render,SIGNAL(vie_generale(int)),this,SLOT(action_vie(int)));
}


window::~window()
{}

void window::action_quit()
{
    close();
}

//Quand on appuie sur le bouton start, les mouvements s'arrêtent
void window::action_start()
{
    render->change_mvtvaisseau();
    render->setFocus();
}

void window::action_alien(int a, int b){

    alien_bleu->setText("alien bleu =" +QString::number(a));
    alien_gris->setText("alien gris =" +QString :: number(b));
}

void window::action_vie(int vie)
{
 nombreVie->setText("VIE JOUEUR : "+QString::number(vie));
}


void window::action_score(int score_joueur)
{
   point_joueur->setText("SCORE JOUEUR: "+QString::number(score_joueur));
}

