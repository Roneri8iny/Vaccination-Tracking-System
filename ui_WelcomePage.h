/********************************************************************************
** Form generated from reading UI file 'WelcomePagesBYAlb.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WELCOMEPAGESBYALB_H
#define WELCOMEPAGESBYALB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomePageClass
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WelcomePage)
    {
        if (WelcomePage->objectName().isEmpty())
            WelcomePage->setObjectName("WelcomePage");
        WelcomePage->resize(1000, 631);
        centralwidget = new QWidget(WelcomePage);
        centralwidget->setObjectName("centralwidget");
        WelcomePage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WelcomePage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        WelcomePage->setMenuBar(menubar);
        statusbar = new QStatusBar(WelcomePage);
        statusbar->setObjectName("statusbar");
        WelcomePage->setStatusBar(statusbar);

        retranslateUi(WelcomePage);

        QMetaObject::connectSlotsByName(WelcomePage);
    } // setupUi

    void retranslateUi(QMainWindow *WelcomePage)
    {
        WelcomePage->setWindowTitle(QCoreApplication::translate("WelcomePage", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomePageClass : public Ui_WelcomePageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WELCOMEPAGESBYALB_H
