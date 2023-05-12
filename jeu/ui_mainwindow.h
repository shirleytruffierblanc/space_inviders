/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *render_zone;
    QVBoxLayout *layout_scene;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *info;
    QHBoxLayout *button_zone;
    QPushButton *start;
    QPushButton *quit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1279, 693);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        render_zone = new QHBoxLayout();
        render_zone->setObjectName(QString::fromUtf8("render_zone"));
        layout_scene = new QVBoxLayout();
        layout_scene->setObjectName(QString::fromUtf8("layout_scene"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout_scene->addItem(horizontalSpacer);


        render_zone->addLayout(layout_scene);

        info = new QVBoxLayout();
        info->setObjectName(QString::fromUtf8("info"));

        render_zone->addLayout(info);


        verticalLayout_2->addLayout(render_zone);

        button_zone = new QHBoxLayout();
        button_zone->setObjectName(QString::fromUtf8("button_zone"));
        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));

        button_zone->addWidget(start);

        quit = new QPushButton(centralwidget);
        quit->setObjectName(QString::fromUtf8("quit"));

        button_zone->addWidget(quit);


        verticalLayout_2->addLayout(button_zone);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1279, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        start->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        quit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
