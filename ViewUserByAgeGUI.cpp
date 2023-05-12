#include "ViewUserByAgeGUI.h"
#include<qmessagebox.h>
#include<unordered_map>
#include<functional>
#include"Admin.h"
using namespace std;
bool flagA, flagD;
Admin admin;
vector<User>::iterator it;

ViewUserByAgeGUI::ViewUserByAgeGUI(vector<User>& secondDoseList, QStackedWidget& stackedWidget,QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ViewAscendingButton = new QPushButton("View Vaccinated Users Ascending", this);
    ViewAscendingButton->move(350, 100);
    ViewAscendingButton->setFixedWidth(300);
    ViewAscendingButton->setFixedHeight(50);
    ViewAscendingButton->setStyleSheet("font-size:16px;");

    ViewDescendingButton = new QPushButton("View Vaccinated Users Descending", this);
    ViewDescendingButton->move(350, 180);
    ViewDescendingButton->setFixedWidth(300);
    ViewDescendingButton->setFixedHeight(50);
    ViewDescendingButton->setStyleSheet("font-size:16px;");

    BackButton = new QPushButton("Back", this);
    BackButton->move(500, 580);
    BackButton->setStyleSheet("font-size:16px;");


    connect(ViewAscendingButton, &QPushButton::clicked, [this, &secondDoseList, &stackedWidget]() {
        onViewAscendingButtonClicked(ref(secondDoseList),ref(stackedWidget));
        });
    connect(ViewDescendingButton, &QPushButton::clicked, [this, &secondDoseList, &stackedWidget]() {
        onViewDescendingButtonClicked(ref(secondDoseList), ref(stackedWidget));
        });
    connect(BackButton, &QPushButton::clicked, [this, &secondDoseList, &stackedWidget]()
        {

            onBackButtonclicked(ref(secondDoseList), ref(stackedWidget));

        });
}



ViewUserByAgeGUI::~ViewUserByAgeGUI()
{
}

void ViewUserByAgeGUI::onViewAscendingButtonClicked(vector<User>& secondDoseList, QStackedWidget& stackedWidget)
{
    vector<User> sorted;
    sorted = admin.viewUsersOrderedByAgeAsc(secondDoseList);
    QString text;

    viewUsersAscTable = new QTableWidget(this);
    viewUsersAscTable->setRowCount(sorted.size());
    viewUsersAscTable->setColumnCount(6);
    QStringList hLables;
    hLables << "Name" << "ID" << "Age" << "Governorate" << "Gender" << "Date";
    viewUsersAscTable->setHorizontalHeaderLabels(hLables);

    viewUsersAscTable->setStyleSheet("font-size:16px;");
    viewUsersAscTable->verticalScrollBar();
    viewUsersAscTable->setGeometry(15, 270, 970, 200);



    for (int i = 0; i < viewUsersAscTable->columnCount(); i++) {
        viewUsersAscTable->setColumnWidth(i, 155);
    }


    for (int i = 0; i < viewUsersAscTable->rowCount(); i++) {
        QTableWidgetItem* item;
        for (int j = 0; j < viewUsersAscTable->columnCount(); j++) {
            item = new QTableWidgetItem;
            if (j == 0) {
                text = QString::fromStdString(sorted[i].getFullName());
                item->setText(text);
            }
            if (j == 1) {
                text = QString::fromStdString(sorted[i].getId());
                item->setText(text);
            }
            if (j == 2) {
                text = QString::number(sorted[i].getAge());
                item->setText(text);
            }
            if (j == 3) {
                text = QString::fromStdString(sorted[i].getGovernorate());
                item->setText(text);
            }
            if (j == 4) {
                if (sorted[i].getMale() == true) {
                    item->setText("Male");
                }
                else {
                    item->setText("Female");
                }
            }
            viewUsersAscTable->setItem(i, j, item);
            item->setFlags(item->flags() & ~(Qt::ItemIsEditable));

        }
    }
    if (flagD == true) {
        viewUsersDescTable->close();
        flagD = false;
    }
    viewUsersAscTable->show();
    flagA = true;
}

void ViewUserByAgeGUI::onViewDescendingButtonClicked(vector<User>& secondDoseList, QStackedWidget& stackedWidget)
{

    vector<User> sorted;
    sorted = admin.viewUsersOrderedByAgeDesc(secondDoseList);
    QString text;

    viewUsersDescTable = new QTableWidget(this);
    viewUsersDescTable->setRowCount(sorted.size());
    viewUsersDescTable->setColumnCount(6);
    viewUsersDescTable->setStyleSheet("font-size:16px;");
    QStringList hLables;
    hLables << "Name" << "ID" << "Age" << "Governorate" << "Gender" << "Date";
    viewUsersDescTable->setHorizontalHeaderLabels(hLables);

    viewUsersDescTable->verticalScrollBar();
    viewUsersDescTable->setGeometry(15, 270, 970, 200);
    //viewUsersTable->move(50, 150);

    for (int i = 0; i < viewUsersDescTable->columnCount(); i++) {
        viewUsersDescTable->setColumnWidth(i, 155);
    }

    for (int i = 0; i < viewUsersDescTable->rowCount(); i++) {
        QTableWidgetItem* item;
        for (int j = 0; j < viewUsersDescTable->columnCount(); j++) {
            item = new QTableWidgetItem;
            if (j == 0) {
                text = QString::fromStdString(sorted[i].getFullName());
                item->setText(text);
            }
            if (j == 1) {
                text = QString::fromStdString(sorted[i].getId());
                item->setText(text);
            }
            if (j == 2) {
                text = QString::number(sorted[i].getAge());
                item->setText(text);
            }
            if (j == 3) {
                text = QString::fromStdString(sorted[i].getGovernorate());
                item->setText(text);
            }
            if (j == 4) {
                if (sorted[i].getMale() == true) {
                    item->setText("Male");
                }
                else {
                    item->setText("Female");
                }
            }
            viewUsersDescTable->setItem(i, j, item);
            item->setFlags(item->flags() & ~(Qt::ItemIsEditable));

        }
    }
    if (flagA == true) {
        viewUsersAscTable->close();
        flagA = false;
    }
    viewUsersDescTable->show();
    flagD = true;
}

void ViewUserByAgeGUI::onBackButtonclicked(vector<User>& secondDoseList, QStackedWidget& stackedWidget)
{
    hide();
    stackedWidget.setCurrentIndex(1);
    stackedWidget.show();
}
