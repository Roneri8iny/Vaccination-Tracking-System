#pragma once

#include <QMainWindow>
#include "ui_ShowStatistics.h"
#include<QPushButton>
#include"C:\Users\ranee\source\repos\VaccineWithGUI\VaccineWithGUI\User.h"
#include<QLabel>
#include<QLineEdit>
#include <QTextEdit>
#include<QStackedWidget>

class ShowStatistics : public QMainWindow
{
	Q_OBJECT

public:
	ShowStatistics(unordered_map<string, User>& userMap, QStackedWidget& stackedWidget, QWidget* parent = nullptr);
	~ShowStatistics();
private slots:

	inline void onPercentageOf1stDoseButtonClicked(unordered_map<string, User>& userMap, QStackedWidget& stackedWidget);
	inline void onviewMailAndFemailPercentageButtonClicked(unordered_map<string, User>& userData, QStackedWidget& stackedWidget);
	inline void onPercentageOf2ndDoseButtonClicked(unordered_map<string, User>& userMap, QStackedWidget& stackedWidget);
	void onBackButtonclicked(unordered_map<string, User>& userMap, QStackedWidget& stackedWidget);

private:
	Ui::ShowStatisticsClass ui;
	QPushButton* PercentageOf1stDose;
	QPushButton* PercentageOf2ndDose;

	QPushButton* PercentageOfGender;

	//QPushButton* button;
	QTextEdit* PercentageOf2ndDoseTextEdit; // New member variable
	QLabel* label;
	unordered_map<string, User> userMap;
	QTextEdit* PercentageOf1stDoseTextEdit;
	QTextEdit* viewMalesPercentageTextEdit;
	QTextEdit* viewFemalesPercentageTextEdit;
	QLabel* malesLabel;
	QLabel* femalesLabel;

	QPushButton* BackButton;

};
