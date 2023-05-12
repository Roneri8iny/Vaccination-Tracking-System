#pragma once
#include "UserView.h"
#include <QtWidgets/QApplication>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <unordered_map>
#include <functional>
#include <string>   
#include <QHeaderView>
#include <QFont>
#include <ctime>
#include <algorithm>
using namespace std;


UserView::UserView(unordered_map<string, User>& userMap, vector<User>& fullyVaccinated, vector<User>& waitForFirstConfirm, vector<User>& waitForSecondConfirm, queue<User>& firstDoseQueue, queue<User>& seconDoseQueue, QStackedWidget& stackedWidget, User user, bool getConfirmation,string& id, QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setFixedSize(1000, 631);
    setStyleSheet("background-color: #CBE5FA;");

    if (getConfirmation) {

        int result = QMessageBox::question(
            parent,  // Parent widget of the message box
            " ",  // Title of the message box
            "Have you taken your dose ?",  // Message displayed in the message box
            QMessageBox::Yes | QMessageBox::No,  // Buttons to display 
            QMessageBox::Yes);  // Default button
        int index;
        string DOSES;
        QDate newdate;
        QString newdateqstring;
        string newdatestring;
        unordered_map<string, User>::iterator It;

        if (result == QMessageBox::Yes) {
            // User clicked the "Yes" button
            // Case doses = 0 --> taken first dose
            if (user.getDoses() == 0) {

                auto it = find_if(waitForFirstConfirm.begin(), waitForFirstConfirm.end(), [&user](User& user1) {
                    return user1.getId() == user.getId();
                    });

                index = distance(waitForFirstConfirm.begin(), it);
                /*newdate = User::assignAppointment();
                newdateqstring = newdate.toString();
                newdatestring = newdateqstring.toStdString();*/
                user.setAppointmentQDate(User::assignAppointment());
                //user.setAppointment(newdatestring);
                //DOSES = to_string(1);
                //user.setDoses(DOSES);
                It = userMap.find(user.getId());
                It->second.setDoses("1");
                It->second.setIsVaccinated(false);
                It->second.setAppointmentQDate(user.getAppointmentQdate());
                user.setDoses("1");
                user.setIsVaccinated(false);
                seconDoseQueue.push(waitForFirstConfirm.at(index));
                auto newEnd = remove(waitForFirstConfirm.begin(), waitForFirstConfirm.end(), user);
                waitForFirstConfirm.erase(newEnd, waitForFirstConfirm.end());
            }
            else if (user.getDoses() == 1) {

                auto it = find_if(waitForSecondConfirm.begin(), waitForSecondConfirm.end(), [&user](User& user1) {
                    return user1.getId() == user.getId();
                    });

                index = distance(waitForSecondConfirm.begin(), it);
                /*newdate = User::assignAppointment();
                newdateqstring = newdate.toString();
                newdatestring = newdateqstring.toStdString();
                user.setAppointment(newdatestring);*/
                user.setAppointmentQDate(User::assignAppointment());
                DOSES = to_string(2);
                //unordered_map<string, User>::iterator It;
                It = userMap.find(user.getId());
                It->second.setDoses("2");
                It->second.setIsVaccinated(true);
                //It->second.setAppointmentQDate(user.getAppointmentQdate());
                user.setDoses("2");
                user.setIsVaccinated(true);
                fullyVaccinated.push_back(waitForSecondConfirm.at(index));
                auto newEnd = remove(waitForSecondConfirm.begin(), waitForSecondConfirm.end(), user);
                waitForSecondConfirm.erase(newEnd, waitForSecondConfirm.end());

            }

        }
        else {
            // User clicked the "No" button or closed the message box
            if (user.getDoses() == 0) {

                auto it = find_if(waitForFirstConfirm.begin(), waitForFirstConfirm.end(), [&user](User& user1) {
                    return user1.getId() == user.getId();
                    });

                index = distance(waitForFirstConfirm.begin(), it);
                /*newdate = User::assignAppointment();
                newdateqstring = newdate.toString();
                newdatestring = newdateqstring.toStdString();
                user.setAppointment(newdatestring);*/
                user.setAppointmentQDate(User::assignAppointment());
                It = userMap.find(user.getId());
                It->second.setAppointmentQDate(user.getAppointmentQdate());
                firstDoseQueue.push(waitForFirstConfirm.at(index));
                auto newEnd = remove(waitForFirstConfirm.begin(), waitForFirstConfirm.end(), user);
                waitForFirstConfirm.erase(newEnd, waitForFirstConfirm.end());
            }
            else if (user.getDoses() == 1) {

                auto it = find_if(waitForSecondConfirm.begin(), waitForSecondConfirm.end(), [&user](User& user1) {
                    return user1.getId() == user.getId();
                    });

                index = distance(waitForSecondConfirm.begin(), it);
               /* newdate = User::assignAppointment();
                newdateqstring = newdate.toString();
                newdatestring = newdateqstring.toStdString();
                user.setAppointment(newdatestring);*/
                user.setAppointmentQDate(User::assignAppointment());
                It = userMap.find(user.getId());
                It->second.setAppointmentQDate(user.getAppointmentQdate());
                seconDoseQueue.push(waitForSecondConfirm.at(index));
                auto newEnd = remove(waitForSecondConfirm.begin(), waitForSecondConfirm.end(), user);
                waitForSecondConfirm.erase(newEnd, waitForSecondConfirm.end());
            }
        }

    }
    fnt.setPointSize(13);

    viewSingleUser = new QTableWidget(this);
    viewSingleUser->setRowCount(1);
    viewSingleUser->setColumnCount(7);
    viewSingleUser->setFixedHeight(100);
    viewSingleUser->setRowHeight(0, 100);
    viewSingleUser->setFont(fnt);
    QStringList hLabels;

    hLabels << "Name" << "Id" << "Gender" << "Age" << "Governorate" << "Doses" << "Next Vaccination Date";

    viewSingleUser->setHorizontalHeaderLabels(hLabels);
    viewSingleUser->setGeometry(10, 50, 975, 120);
    viewSingleUser->setFixedHeight(120);
    viewSingleUser->horizontalHeader()->setStyleSheet("QHeaderView {font: bold 15px;}");
    viewSingleUser->horizontalHeader()->setStyleSheet("background - color: #CBE5FA; ");
    QString text;

    for (int i = 0; i < viewSingleUser->columnCount(); i++)
    {
        //viewSingleUser->setColumnWidth(i, 135);

        item = new QTableWidgetItem;
        if (i == 0)   //  Name
        {
            viewSingleUser->setColumnWidth(i, 195);
            text = QString::fromStdString(user.getFullName());
            item->setText(text);
        }
        else if (i == 1)  // ID
        {
            viewSingleUser->setColumnWidth(i, 135);
            text = QString::fromStdString(user.getId());
            item->setText(text);
        }
        else if (i == 2)
        {
            viewSingleUser->setColumnWidth(i, 115);

            if (user.getMale() == true)
            {
                item->setText("Male");
            }
            else
            {
                item->setText("Female");
            }
        }
        else if (i == 3)
        {
            viewSingleUser->setColumnWidth(i, 115);
            text = QString::number(user.getAge());
            item->setText(text);
        }

        else if (i == 4)
        {
            viewSingleUser->setColumnWidth(i, 115);
            text = QString::fromStdString(user.getGovernorate());
            item->setText(text);
        }
        else if (i == 5)
        {
            viewSingleUser->setColumnWidth(i, 115);
            text = QString::number(user.getDoses());
            item->setText(text);
        }
        else if (i == 6) {
            viewSingleUser->setColumnWidth(i, 165);
            text = user.getAppointmentQdate().toString();
            item->setText(text);
        }
        viewSingleUser->setItem(0, i, item);
        item->setFlags(item->flags() & ~(Qt::ItemIsEditable));
    }

    viewSingleUser->show();

    deleteMSG = new QLabel("If you want to delete your account, click here ->", this);
    deleteMSG->move(50, 250);
    deleteMSG->setFixedWidth(900);
    deleteMSG->setStyleSheet("font: bold 20px;");

    deleteUserAccount = new QPushButton("Delete", this);
    deleteUserAccount->move(520, 250);
    deleteUserAccount->setFixedWidth(250);
    deleteUserAccount->setFixedHeight(40);
    deleteUserAccount->setStyleSheet("font: bold 20px;");

    logOut = new QPushButton("Log Out", this);
    logOut->move(350, 500);
    logOut->setFixedWidth(250);
    logOut->setFixedHeight(40);
    logOut->setStyleSheet("font: bold 20px;");


    editMSG = new QLabel("If you want to edit your personal data, click here ->", this);
    editMSG->move(50, 400);
    editMSG->setFixedWidth(500);
    editMSG->setStyleSheet("font: bold 20px;");

    editUserInfo = new QPushButton("Edit your data", this);
    editUserInfo->move(550, 395);
    editUserInfo->setFixedWidth(250);
    editUserInfo->setFixedHeight(40);
    editUserInfo->setStyleSheet("font: bold 20px;");

    showUsers = new QPushButton("Users", this);
    showUsers->move(0, 600);
    showUsers->hide();

    //string tempID = user.getId();
    //logoutButton = new QPushButton("Log Out", this);
    //logoutButton->move(420, 550);
    //logoutButton->setFixedSize(100, 50);

    connect(deleteUserAccount, &QPushButton::clicked, [this, &userMap, &firstDoseQueue, &seconDoseQueue, &fullyVaccinated,user]()
    {
            // use lambda function to capture value
            onDeleteButtonPressed(ref(userMap), ref(firstDoseQueue), ref(seconDoseQueue), ref(fullyVaccinated), user);
            // call slot function with value as argument
    });

    edituserwindow = new EditUserWindow(userMap, firstDoseQueue, seconDoseQueue, fullyVaccinated, id, waitForFirstConfirm, waitForSecondConfirm ,stackedWidget , viewSingleUser);

    connect(editUserInfo, &QPushButton::clicked, [this, &stackedWidget, &userMap, &fullyVaccinated, &waitForFirstConfirm, &waitForSecondConfirm, &firstDoseQueue, &seconDoseQueue]()
        {
            // use lambda function to capture value
            on_Edit_Button_clicked(userMap, fullyVaccinated,  waitForFirstConfirm, waitForSecondConfirm, firstDoseQueue, seconDoseQueue, stackedWidget);            // call slot function with value as argument
        });

    connect(logOut, &QPushButton::clicked, [this, &stackedWidget, &userMap, &fullyVaccinated, &waitForFirstConfirm, &waitForSecondConfirm, &firstDoseQueue, &seconDoseQueue]()
        {
            // use lambda function to capture value
            onLogOutButtonPressed(userMap, fullyVaccinated, waitForFirstConfirm, waitForSecondConfirm, firstDoseQueue, seconDoseQueue, stackedWidget);            // call slot function with value as argument
        });


    //connect(showUsers, &QPushButton::clicked, [this, &userMap]()
    //    {
    //        // use lambda function to capture value
    //        buttonPressed(ref(userMap));
    //        // call slot function with value as argument
    //    });

    //connect(password, &QLineEdit::returnPressed, [this, &userdata , id]()
    //    {
    //        // use lambda function to capture value
    //        deletePressed(ref(userdata),id);
    //        // call slot function with value as argument
    //    });}
}

UserView::~UserView()
{

}


//QString getDate()
//{
//    struct tm newtime;
//    time_t now = time(0);
//    localtime_s(&newtime, &now);
//    int Day = newtime.tm_wday;
//    int Month = 1 + newtime.tm_mon;
//    int Year = 1900 + newtime.tm_year;
//    int Hour = newtime.tm_hour;
//    int Minute = newtime.tm_min;
//    int Seconds = newtime.tm_sec;
//
//    string day = to_string(Day);
//    string month = to_string(Month);
//    string year = to_string(Year);
//    string hour = to_string(Hour);
//    string minute = to_string(Minute);
//    string seconds = to_string(Seconds);
//
//    string fullDate = day + "/" + month + "/" + year + "  " + hour + ":" + minute + ":" + seconds;
//
//    QString FullDate = QString::fromStdString(fullDate);
//    return FullDate;
//}

//void UserView::buttonPressed(unordered_map <string, User>& userMap) {
//    unordered_map <string, User> ::iterator it;
//    QString allUsers = "";
//    QMessageBox msg;
//    if (userMap.empty())
//    {
//        msg.setText("No Users");
//        msg.exec();
//    }
//    else
//    {
//        for (it = userMap.begin(); it != userMap.end(); it++) {
//            QString fullName = QString::fromStdString(it->second.getFullName());
//            allUsers = allUsers + fullName + "\n";
//        }
//        msg.setText(allUsers + "\n" + getDate());
//        msg.exec();
//    }
//}
//

void UserView::onDeleteButtonPressed(unordered_map <string, User>& userMap, queue<User>& firstDoseQueue, queue<User>& seconDoseQueue, vector<User>& fullyVaccinated, User user)
{
    QMessageBox msg1;
    msg1.setWindowTitle(" ");
    //string temp = password->text().toStdString();
    ////User user = userMap.at(id);

    user.deleteUserInfo(userMap, firstDoseQueue, seconDoseQueue, fullyVaccinated, user);
    msg1.setText("Done");
    msg1.exec();
    /*if (user.getPassword() == temp)
    {
        user.deleteUserInfo(userMap , firstDoseQueue, seconDoseQueue, fullyVaccinated , user);
        msg1.setText("Done");
    }
    else if (temp == "")
    {
        msg1.setText("Enter Your Password");
    }
    else
    {
        msg1.setText("Invalid Password");

    }
    msg1.exec();*/
}
//void firstWindow::deletePressed(unordered_map <string, User>& userdata, string id)
//{
//    //unordered_map <string, User> ::iterator it;
//    QMessageBox msg1;
//    msg1.setWindowTitle(" ");
//   // bool check = false;
//    if (userdata[id].getPassword() == password->text().toStdString())
//    {
//        userdata[id].deleteUserInfo(userdata);
//        msg1.setText("Done");
//    }
//    else
//    {
//        msg1.setText("Invalid Password");
//
//    }
//    /*for (it = userdata.begin(); it != userdata.end(); it++)
//    {
//        if (it->second.getPassword() == password->text().toStdString())
//        {
//            check = true;
//            userdata.find(it->second.getId())->second.deleteUserInfo(userdata);
//            break;
//        }
//    }
//
//    if (check == true)
//    {
//        msg1.setText("Done");
//    }
//    else
//    {
//        msg1.setText("Invalid Password");
//
//    }*/
//    msg1.exec();
//
//}

void UserView::onLogOutButtonPressed(unordered_map<string, User>& userMap, vector<User>& fullyVaccinated, vector<User>& waitForFirstConfirm, vector<User>& waitForSecondConfirm, queue<User>& firstDoseQueue, queue<User>& seconDoseQueue, QStackedWidget& stackedWidget)
{
    close();
    stackedWidget.removeWidget(this);
    stackedWidget.removeWidget(edituserwindow);
    stackedWidget.setCurrentIndex(0);
    stackedWidget.show();
}

void UserView::on_Edit_Button_clicked(unordered_map<string, User>& userMap, vector<User>& fullyVaccinated, vector<User>& waitForFirstConfirm, vector<User>& waitForSecondConfirm, queue<User>& firstDoseQueue, queue<User>& seconDoseQueue, QStackedWidget& stackedWidget )
{
    hide();
    stackedWidget.addWidget(edituserwindow);  // index 2
    stackedWidget.setCurrentWidget(edituserwindow);
    stackedWidget.show();
}