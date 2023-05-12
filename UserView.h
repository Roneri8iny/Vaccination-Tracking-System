#pragma once

#include <QMainWindow>
#include "ui_UserView.h"
#include <QtWidgets/QMainWindow>
#include <unordered_map>
#include <string>
#include"C:\Users\ranee\source\repos\VaccineWithGUI\VaccineWithGUI\User.h"
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFont>
#include "EditUserWindow.h"
#include <QStackedWidget>
#include <QWidget>


using namespace std;

class UserView : public QMainWindow
{
	Q_OBJECT

public:
	UserView(unordered_map<string, User>&, vector<User>&, vector<User>&, vector<User>&, queue<User>&, queue<User>&, QStackedWidget&, User, bool,string&, QWidget* parent = nullptr);
	~UserView();
    QTableWidget* viewSingleUser;
    QTableWidgetItem* item;

private:
	Ui::UserViewClass ui;
    QPushButton* showUsers;
    //QPushButton* logoutButton;
    QLabel* deleteMSG;
    QLabel* editMSG;
    QPushButton* deleteUserAccount;
    QPushButton* editUserInfo;
    QPushButton* logOut;
    QFont fnt;
    EditUserWindow* edituserwindow;

private slots:
    //void buttonPressed(unordered_map <string, User>&);
    // void deletePressed(unordered_map <string, User>& , string);
    void onDeleteButtonPressed(unordered_map <string, User>&, queue<User>&, queue<User>&, vector<User>&, User);
    void onLogOutButtonPressed(unordered_map<string, User>& , vector<User>& , vector<User>& , vector<User>& , queue<User>& , queue<User>& , QStackedWidget& );
    void on_Edit_Button_clicked(unordered_map<string, User>& userMap, vector<User>& fullyVaccinated, vector<User>& waitForFirstConfirm, vector<User>& waitForSecondConfirm, queue<User>& firstDoseQueue, queue<User>& seconDoseQueue, QStackedWidget& stackedWidget);

};
