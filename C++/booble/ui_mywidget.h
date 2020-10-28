/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(400, 300);
        menuBar = new QMenuBar(MyWidget);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MyWidget->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyWidget);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyWidget->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyWidget);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MyWidget->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyWidget);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyWidget->setStatusBar(statusBar);

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QMainWindow *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
