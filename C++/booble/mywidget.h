#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtGui>
#include <QWidget>
#include <QList>
#include <qrandom.h>
//https://www.cyberforum.ru/cpp-beginners/thread274646.html
class myRect : public QRect{
public:
    int dxr;
    int dyr;
};

class MyWidget : public QWidget {
    Q_OBJECT
    int dx;
    int dy;
    myRect circleBounds;

    /*int dx2;
    int dy2;
    QRect circleBounds2;*/
    QList<myRect> listRect;

public:
    MyWidget(QWidget * parent) : QWidget(parent) {

        circleBounds.dxr = 6;
        circleBounds.dyr = 4;
        circleBounds.setLeft(34);
        circleBounds.setTop(21);
        circleBounds.setWidth(10);
        circleBounds.setHeight(10);
        listRect.append(circleBounds);

        /*dx2 = 2;
        dy2 = 1;
        circleBounds2.setLeft(300);
        circleBounds2.setTop(300);
        circleBounds2.setWidth(50);
        circleBounds2.setHeight(50);
        */

        QTimer * timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
        timer->start(10);
    }

    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::white);
        painter.drawRect(rect());
        int a = (qrand() % ((3 + 1) - 0) + 0);
        for( int i = 0; i < listRect.count(); i++ ) {
            if ( ( listRect[i].left() + listRect[i].dxr ) < 0 || ( listRect[i].right() + listRect[i].dxr ) > this->rect().width() ){
                listRect[i].dxr = -listRect[i].dxr-(qrand() % ((3 + 1) - 0) + 0);
                circleBounds.setLeft((qrand() % ((480 + 1) - 10) + 10));
                circleBounds.setTop((qrand() % ((480 + 1) - 10) + 10));
                circleBounds.dxr = (qrand() % ((5 + 1) - (-5)) + (-5));
                circleBounds.dyr = (qrand() % ((5 + 1) - (-5)) + (-5));
                listRect.append(circleBounds);
                if(a == 2 or a == 1){
                    listRect.pop_back();
                }
            }

            if ( ( listRect[i].top() + listRect[i].dyr ) < 0 || ( listRect[i].bottom() + listRect[i].dyr ) > this->rect().height() ){
                listRect[i].dyr = -listRect[i].dyr-(qrand() % ((3 + 1) - 0) + 0);
                circleBounds.setLeft((qrand() % ((480 + 1) - 10) + 10));
                circleBounds.setTop((qrand() % ((480 + 1) - 10) + 10));
                circleBounds.dxr = (qrand() % ((5 + 1) - (-5)) + (-5));
                circleBounds.dyr = (qrand() % ((5 + 1) - (-5)) + (-5));
                listRect.append(circleBounds);
                if(a == 1 or a == 2){
                    listRect.pop_back();
                }
            }
            listRect[i].setLeft(listRect[i].left() + listRect[i].dxr);
            listRect[i].setTop(listRect[i].top() + listRect[i].dyr);
            listRect[i].setWidth(10);
            listRect[i].setHeight(10);

            painter.setBrush(Qt::blue);
            painter.drawEllipse(listRect[i]);
        }

        /*
        if ( ( circleBounds2.left() + dx2 ) < 0 || ( circleBounds2.right() + dx2 ) > this->rect().width() ){
            dx2 = -dx2-1;
        }

        if ( ( circleBounds2.top() + dy2 ) < 0 || ( circleBounds2.bottom() + dy2 ) > this->rect().height() ){
            dy2 = -dy2-2;
        }
        */
        /*
        circleBounds2.setLeft(circleBounds2.left() + dx2);
        circleBounds2.setTop(circleBounds2.top() + dy2);
        circleBounds2.setWidth(50);
        circleBounds2.setHeight(50);
        */
       // painter.drawEllipse(circleBounds2);
    }

};

#endif // MYWIDGET_H
