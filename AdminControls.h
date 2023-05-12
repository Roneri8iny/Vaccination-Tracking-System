#pragma once

#include <QMainWindow>
#include "ui_AdminControls.h"
#include <qstackedwidget.h>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include"C:\Users\ranee\source\repos\VaccineWithGUI\VaccineWithGUI\User.h"
#include<vector>
class AdminControls : public QMainWindow
{
	Q_OBJECT

public:
	AdminControls(unordered_map<string, User>& userMap, queue<User>& waitingList, queue<User>& firstDoseList, vector<User>& secondDoseList, QStackedWidget& stackedWidget, QWidget* parent = nullptr);
	~AdminControls();
private slots:


	void onViewUserButtonClicked(unordered_map<string, User>& userMap, QStackedWidget& stackedWidget);
	void onDeleteUserButtonButtonClicked(unordered_map<string, User>& userMap, queue<User>& waitingList, queue<User>& firstDoseList, vector<User>& secondDoseList, QStackedWidget& stackedWidget);
	void onWaitingListButtonButtonClicked(queue<User>& waitingList, QStackedWidget& stackedWidget);
	void onshowStatisticsButtonClicked(unordered_map<string, User>& userMap, QStackedWidget& stackedWidget);
	void onViewWhoRecivedByDoseButtonClicked(unordered_map<string, User>& userMap, QStackedWidget& stackedWidget);
	void onViewByAgeButtonClicked(vector<User>& secondDoseList, QStackedWidget& stackedWidget);
	void onlogoutButtonClicked(unordered_map<string, User>& userMap, queue<User>& waitingList, queue<User>& firstDoseList, vector<User>& secondDoseList, QStackedWidget& stackedWidget);

private:
	Ui::AdminControlsClass ui;


	QPushButton* ViewUserButton;
	QPushButton* LogOut;

	QPushButton* deleteUserButton;


	QPushButton* WaitingListButton;
	QPushButton* showStatisticsButton;

	QPushButton* ViewWhoRecivedByDoseButton;

	QPushButton* ViewByAgeButton;

};
