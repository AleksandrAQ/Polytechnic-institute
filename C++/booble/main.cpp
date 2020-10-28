//Авферонок Александр в3530904/80022
/*
 * Задание:
 * шарик, он ударяется об стенку и делится на три шарика, которые потом тоже делятся, или взрываются.
 */

#include <QApplication>
#include <QtGui>
#include "mywidget.h"


int main(int argc, char ** argv){
    QApplication app(argc, argv);
    MyWidget mw(nullptr);

    mw.resize(700, 700);
    mw.show();

    return app.exec();
}
