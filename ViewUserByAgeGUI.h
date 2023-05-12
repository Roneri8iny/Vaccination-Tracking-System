#pragma once

#include <QMainWindow>
#include "ui_ViewUserByAgeGUI.h"
#include<unordered_map>
#include<string>
#include"C:\Users\ranee\source\repos\VaccineWithGUI\VaccineWithGUI\User.h"
#include<QPushButton>
#include<QTableWidget>
#include<QStackedWidget>
using namespace std;


class ViewUserByAgeGUI : public QMainWindow
{
	Q_OBJECT

public:
	ViewUserByAgeGUI(vector<User>& secondDoseList, QStackedWidget& stackedWidget, QWidget* parent = nullptr);
	~ViewUserByAgeGUI();
private slots:

	void onViewAscendingButtonClicked(vector<User>& secondDoseList, QStackedWidget& stackedWidget);
	void onViewDescendingButtonClicked(vector<User>& secondDoseList, QStackedWidget& stackedWidget);
	void onBackButtonclicked(vector<User>& secondDoseList, QStackedWidget& stackedWidget);
private:
	Ui::ViewUserByAgeGUIClass ui;
	QPushButton* ViewAscendingButton;
	QPushButton* ViewDescendingButton;
	QTableWidget* viewUsersAscTable;
	QTableWidget* viewUsersDescTable;
	QPushButton* BackButton;

};

