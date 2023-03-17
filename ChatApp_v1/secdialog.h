#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QTimer>
#include "Server.h"

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);

    void setupServerConnection();
    ~SecDialog();
public slots :
    void timeOperationForClock();
    void datetimeOperationForClock();
    void updateOnlineUsersLabel();
    void updateOnlineUsersLabelText();
private slots:
    void on_sendButton_clicked();
private:
    Ui::SecDialog *ui;
    QTimer *timer;
    Server *server;
};

#endif // SECDIALOG_H
