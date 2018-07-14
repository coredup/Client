#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisc()));
}

Client::~Client()
{
    delete ui;
}

void Client::on_pushButton_clicked()
{
    socket->connectToHost("127.0.0.1",5555);
}

void Client::sockDisc()
{
    socket->deleteLater();
}

void Client::sockReady()
{
    if (socket->waitForConnected(500))
    {
       socket->waitForReadyRead(500);
       Data = socket->readAll();
       qDebug()<<Data;
    }
}
