#pragma once

#include <QMainWindow>
#include "ui_ViewUserByDose.h"
#include  <QTableWidget>
#include<QStackedWidget>
#include "Admin.h"
#include"C:\Users\ranee\source\repos\VaccineWithGUI\VaccineWithGUI\User.h"
#include<unordered_map>
#include<QPushButton>
class ViewUserByDose : public QMainWindow
{
	Q_OBJECT

public:
	ViewUserByDose(unordered_map<string, User>& userMap, QStackedWidget& stackedWidget,QWidget* parent = nullptr);
	~ViewUserByDose();
private slots:


	void onwhoRecieved1stDoseButtonClicked(unordered_map<string, User>& userMap, QStackedWidget& stackedWidget);
	void onwhoRecieved2ndDoseButtonClicked(unordered_map<string, User>& userMap, QStackedWidget& stackedWidget);
	void onBackButtonClicked(unordered_map<string, User>& userMap, QStackedWidget& stackedWidget);

private:
	Ui::ViewUserByDoseClass ui;
	QTableWidget* whoRecieved1stDoseTable;
	QTableWidget* whoRecieved2ndDoseTable;

	QPushButton* whoRecieved1stDoseButton;
	QPushButton* whoRecieved2ndDoseButton;
	QPushButton* BackButton;
};
