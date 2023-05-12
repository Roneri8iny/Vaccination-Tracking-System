#pragma once

#include <QMainWindow>
#include "ui_viewWaitingList.h"
#include<QPushButton>
#include<QTextEdit>
#include<QLabel>
#include<unordered_map>
#include"C:\Users\ranee\source\repos\VaccineWithGUI\VaccineWithGUI\User.h"
#include"Admin.h"
#include<QDate>
#include<QTableWidget>
#include<QFont>
#include<queue>
#include<QStackedWidget>

class viewWaitingList : public QMainWindow
{
	Q_OBJECT

public:
	viewWaitingList(queue<User>& waitingList, QStackedWidget& stackedWidget, QWidget* parent = nullptr);
	~viewWaitingList();

private slots:
	inline void tableDisplay(queue<User>& waitingList, QStackedWidget& stackedWidget);
	void onbackButtonclicked(queue<User>& waitingList, QStackedWidget& stackedWidget);

private:
	Ui::viewWaitingListClass ui;
	Admin a;
	QPushButton* button;
	queue<User> firstDose;
	QFont font;
	QPushButton* backButton;
};
