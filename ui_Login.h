/********************************************************************************
** Form generated from reading UI file 'VaccineTrackingSystemePGhFZ.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef VACCINETRACKINGSYSTEMEPGHFZ_H
#define VACCINETRACKINGSYSTEMEPGHFZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *ID_Label;
    QLabel *Password_Label;
    QPushButton *Sign_Up_Button;
    QLabel *label_4;
    QLineEdit *ID_TextBox;
    QLineEdit *Password_TextBox;
    QPushButton *Back_Button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VaccineTrackingSystemClass)
    {
        if (VaccineTrackingSystemClass->objectName().isEmpty())
            VaccineTrackingSystemClass->setObjectName("VaccineTrackingSystemClass");
        VaccineTrackingSystemClass->resize(988, 587);
        centralWidget = new QWidget(VaccineTrackingSystemClass);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 10, 641, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(26);
        font.setBold(true);
        label->setFont(font);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 80, 951, 311));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(20);
        font1.setBold(true);
        groupBox->setFont(font1);
        ID_Label = new QLabel(groupBox);
        ID_Label->setObjectName("ID_Label");
        ID_Label->setGeometry(QRect(160, 70, 151, 41));
        Password_Label = new QLabel(groupBox);
        Password_Label->setObjectName("Password_Label");
        Password_Label->setGeometry(QRect(160, 120, 131, 41));
        /*Sign_Up_Button = new QPushButton(groupBox);
        Sign_Up_Button->setObjectName("Sign_Up_Button");
        Sign_Up_Button->setGeometry(QRect(140, 260, 161, 41));*/
       // label_4 = new QLabel(groupBox);
        //label_4->setObjectName("label_4");
        //label_4->setGeometry(QRect(20, 220, 431, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(16);
        font2.setBold(true);
        //label_4->setFont(font2);
        ID_TextBox = new QLineEdit(groupBox);
        ID_TextBox->setObjectName("ID_TextBox");
        ID_TextBox->setGeometry(QRect(320, 70, 301, 31));
        Password_TextBox = new QLineEdit(groupBox);
        Password_TextBox->setObjectName("Password_TextBox");
        Password_TextBox->setGeometry(QRect(320, 120, 301, 31));
        /*Back_Button = new QPushButton(centralWidget);
        Back_Button->setObjectName("Back_Button");
        Back_Button->setGeometry(QRect(60, 460, 161, 41));*/
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(24);
        font3.setBold(true);
        //Back_Button->setFont(font3);
        VaccineTrackingSystemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VaccineTrackingSystemClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 988, 22));
        VaccineTrackingSystemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VaccineTrackingSystemClass);
        mainToolBar->setObjectName("mainToolBar");
        VaccineTrackingSystemClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VaccineTrackingSystemClass);
        statusBar->setObjectName("statusBar");
        VaccineTrackingSystemClass->setStatusBar(statusBar);

        retranslateUi(VaccineTrackingSystemClass);

        QMetaObject::connectSlotsByName(VaccineTrackingSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *VaccineTrackingSystemClass)
    {
        VaccineTrackingSystemClass->setWindowTitle(QCoreApplication::translate("VaccineTrackingSystemClass", "VaccineTrackingSystem", nullptr));
        label->setText(QCoreApplication::translate("VaccineTrackingSystemClass", "Welcome To Vaccine Tracking System", nullptr));
        groupBox->setTitle(QCoreApplication::translate("VaccineTrackingSystemClass", "Login", nullptr));
        ID_Label->setText(QCoreApplication::translate("VaccineTrackingSystemClass", "National ID", nullptr));
        Password_Label->setText(QCoreApplication::translate("VaccineTrackingSystemClass", "Password", nullptr));
        //Sign_Up_Button->setText(QCoreApplication::translate("VaccineTrackingSystemClass", "Sign Up", nullptr));
       // label_4->setText(QCoreApplication::translate("VaccineTrackingSystemClass", "If You Do not have an Account, Press Here", nullptr));
        //Back_Button->setText(QCoreApplication::translate("VaccineTrackingSystemClass", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginClass: public Ui_LoginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // VACCINETRACKINGSYSTEMEPGHFZ_H
