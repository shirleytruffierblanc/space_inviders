
#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include <QLabel>

//forward declaration
namespace Ui{
class MainWindow;
}
class render_area;

/** Declaration of the window class */
class window: public QMainWindow
{
    Q_OBJECT

public:

    window(QWidget *parent=nullptr);
    ~window();

private slots:

    void action_quit();
    void action_start();
    void action_alien(int a, int b);
    void action_score(int score);
    void action_vie(int vie);

private:

    Ui::MainWindow *ui;
    render_area *render;

    QLabel *nombreVie;
    QLabel *point_joueur;
    QLabel *alien_bleu;
    QLabel *alien_gris;


};

#endif
