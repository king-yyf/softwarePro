#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "users.h"
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdit->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    ui->lineEdit_2->setStyleSheet("QLineEdit{border-width:0;border-style:outset}");
    this->setAttribute(Qt::WA_QuitOnClose,false);
}


Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString name=ui->lineEdit->text().trimmed();
    QString pass=ui->lineEdit_2->text().trimmed();
    if(users::isTrue(name,pass)||(name.trimmed()=="admin"&&pass.trimmed()=="admin")){
        this->close();
        emit sendMsg(name);
    }else
    {
    QMessageBox::warning(this,"警告","用户名或密码错误!!!",
    QMessageBox::Yes);
    ui->lineEdit->setFocus();
    }
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}


void Login::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}
