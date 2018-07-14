#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
    class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();

    QTcpSocket* socket;
    QByteArray Data;

public slots:
    void sockReady();
    void sockDisc();

private:
    Ui::Client *ui;

private slots:
    void on_pushButton_clicked();
};

#endif // CLIENT_H
