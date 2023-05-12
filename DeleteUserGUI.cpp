#include "DeleteUserGUI.h"
#include<qmessagebox.h>
#include<QString>
#include<string>
#include<functional>
#include"Admin.h"
using namespace std;
QString allusers = " ";

DeleteUserGUI::DeleteUserGUI(unordered_map<string, User>& userData, queue<User>& waitingList, queue<User>& firstDoseList, vector<User>& secondDoseList, QStackedWidget& stackedWidget, QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //delete one user
    deleteOneUserButton = new QPushButton("Delete User", this);
    deleteOneUserButton->move(510, 180);
    deleteOneUserButton->setFixedWidth(150);
    deleteOneUserButton->setFixedHeight(32);
    deleteOneUserButton->setStyleSheet("font-size:16px;");

    deleteIDLabel = new QLabel("Enter ID: ", this);
    deleteIDLabel->move(260, 180);
    deleteIDLabel->setStyleSheet("font-size:16px;");

    deleteIDlineEdit = new QLineEdit(this);
    deleteIDlineEdit->move(330, 180);
    deleteIDlineEdit->setFixedWidth(170);
    deleteIDlineEdit->setStyleSheet("font-size:15px;");

    connect(deleteOneUserButton, &QPushButton::clicked, [this, &userData, &waitingList, &firstDoseList, &secondDoseList,&stackedWidget]() {
        ondeleteOneUserButtonClicked(ref(userData), ref(waitingList), ref(firstDoseList), ref(secondDoseList),ref(stackedWidget));
        });

    //delete all users
    deleteAllUsersButton = new QPushButton("Delete All Users ", this);
    deleteAllUsersButton->move(340, 250);
    deleteAllUsersButton->setFixedWidth(300);
    deleteAllUsersButton->setFixedHeight(40);
    deleteAllUsersButton->setStyleSheet("font-size:16px;");

    //Back Button
    BackButton = new QPushButton("Back", this);
    BackButton->move(500, 580);
    BackButton->setStyleSheet("font-size:16px;");

    connect(deleteAllUsersButton, &QPushButton::clicked, [this, &userData, &waitingList, &firstDoseList, &secondDoseList, &stackedWidget]() {
        ondeleteAllUsersButtonClicked(ref(userData), ref(waitingList), ref(firstDoseList), ref(secondDoseList), ref(stackedWidget));
        });

    connect(BackButton, &QPushButton::clicked, [this, &secondDoseList, &stackedWidget]()
        {

            onBackButtonclicked(ref(secondDoseList), ref(stackedWidget));

        });
}
void DeleteUserGUI::ondeleteOneUserButtonClicked(unordered_map<string, User>& userData, queue<User>& waitingList, queue<User>& firstDoseList, vector<User>& secondDoseList, QStackedWidget& stackedWidget)
{
    Admin admin;
    unordered_map<string, User>::iterator it;
    QString id = deleteIDlineEdit->text();
    string userId = id.toStdString();
    QString deleted_name;


    it = userData.find(userId);
    if (it == userData.end()) {
        QMessageBox::warning(this, "Wrong Information", "this National Id is not found.");
    }
    else {
        for (it = userData.begin(); it != userData.end(); it++) {
            if (it->second.getId() == userId) {
                deleted_name = QString::fromStdString(it->second.getFullName());
            }
        }
        admin.deleteUser(userData, waitingList, firstDoseList, secondDoseList, userId);
        for (it = userData.begin(); it != userData.end(); it++) {
            QString name = QString::fromStdString(it->second.getFullName());
            allusers = allusers + name + "\n";
        }
        QMessageBox::information(this, "Delete Information", deleted_name + " is deleted successfully");
        QMessageBox::information(this, "Delete Information", " all Users: \n" + allusers);
    }

}

void DeleteUserGUI::ondeleteAllUsersButtonClicked(unordered_map<string, User>& userData, queue<User>& waitingList, queue<User>& firstDoseList, vector<User>& secondDoseList, QStackedWidget& stackedWidget)
{
    Admin admin;
    QMessageBox::information(this, "Delete Information", "all Users are deleted successfully.");
    QString size1 = QString::number(userData.size());
    QMessageBox::information(this, "Delete Information", "hashTable size is : " + size1);
    admin.deleteAllUsers(userData, waitingList, firstDoseList, secondDoseList);
    QString size2 = QString::number(userData.size());
    QMessageBox::information(this, "Delete Information", "hashTable size is : " + size2);

}

void DeleteUserGUI::onBackButtonclicked(vector<User>& secondDoseList, QStackedWidget& stackedWidget)
{
    hide();
    stackedWidget.setCurrentIndex(1);
    stackedWidget.show();
}

DeleteUserGUI::~DeleteUserGUI()
{}
