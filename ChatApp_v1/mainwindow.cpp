#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPixmap>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Kemal/Documents/ChatApp_v1/pic.png");
    int w = ui -> label_pic -> width();
    int h = ui -> label_pic -> height();
    ui -> label_pic -> setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->username_lineEdit->text();
    QString password = ui->password_lineEdit->text();

    QFile file("C:/Users/Kemal/Documents/ChatApp_v1/dataBase.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);

    QJsonArray jsonArray = doc.array();

    bool loginSuccessful = false;
    for (int i = 0; i < jsonArray.size(); i++) {
        QJsonObject user = jsonArray[i].toObject();
        if (user["username"].toString() == username && user["password"].toString() == password) {
            loginSuccessful = true;
            break;
        }
    }

    if (loginSuccessful) {

        QMessageBox::information(this, "Login", "Username and password is correct");
        hide();
        secDialog = new SecDialog(this);
        secDialog->show();
    } else {

        QMessageBox::warning(this, "Login", "Username and password is not correct");
    }
}

void MainWindow::on_pushButton_register_clicked()
{

    QString username = ui->username_lineEdit->text();
    QString password = ui->password_lineEdit->text();


    QFile file("C:/Users/Kemal/Documents/ChatApp_v1/dataBase.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);


    QJsonArray jsonArray = doc.array();


    bool usernameExists = false;
    for (int i = 0; i < jsonArray.size(); i++) {
        QJsonObject user = jsonArray[i].toObject();
        if (user["username"].toString() == username) {
            usernameExists = true;
            break;
        }
    }

    if (usernameExists) {

        QMessageBox::warning(this, "Error", "Username already exists.");
    } else {

        QJsonObject newUser;
        newUser["username"] = username;
        newUser["password"] = password;
        newUser["id"] = QString::number(jsonArray.size() + 1);
        jsonArray.append(newUser);


        QJsonDocument newDoc(jsonArray);
        file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
        file.write(newDoc.toJson());
        file.close();


        QMessageBox::information(this, "Success", "Registration Successful!");
    }
}

