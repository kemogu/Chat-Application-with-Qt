#include "secdialog.h"
#include "ui_secdialog.h"
#include "Server.h"

#include <QDebug>
#include <QTimer>
#include <QDateTime>


SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    // Server nesnesini oluştur ve bağlantıları yapılandır
    server = new Server(this);
    connect(server, &Server::onlineUsersChanged, this, &SecDialog::updateOnlineUsersLabel);

    // Saat ve tarih işlevleri için zamanlayıcıyı başlat
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeOperationForClock()));
    connect(timer, SIGNAL(timeout()), this, SLOT(datetimeOperationForClock()));
    timer->start();
}

SecDialog::~SecDialog()
{
    delete ui;
    delete server; // Server nesnesini sil
}

void SecDialog::timeOperationForClock()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh:mm:ss");
    ui->clock_label->setText(time_text);

}

void SecDialog::datetimeOperationForClock()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeText = dateTime.toString("dd.MM.yyyy");
    ui->dateTime_label->setText(dateTimeText);
}

void SecDialog::on_sendButton_clicked()
{
    // Mesajı TCP ile gönder

    QString message = ui->messageBox->toPlainText();
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh:mm:ss");

    int messageLength = message.length() + 8 ;
    int blank = abs(200 - messageLength);
    QString mesBlank = " ";
    for (int i = 1; i <= blank - 1; i++)
    {
        if (message.length() > 200)
        {
            // Özel Durum
        }
        mesBlank = mesBlank + " ";
    }
    QString newMessage = message + mesBlank + time_text ;

    ui->messageBrowser->insertPlainText(newMessage);
    ui->messageBox->clear();
    QString newLine = "\n\n" ;
    ui->messageBrowser->insertPlainText(newLine);
}

void SecDialog::updateOnlineUsersLabel()
{
    QMetaObject::invokeMethod(this, "updateOnlineUsersLabelText", Qt::QueuedConnection);
}
void SecDialog::updateOnlineUsersLabelText()
{
    int onlineUserCount = server->getClientCount();
    QString label_text = "Online users: " + QString::number(onlineUserCount);
    ui->label_off_or_online->setText(label_text);
}

