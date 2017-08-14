#include "users.h"
#include "ui_users.h"
#include <QMessageBox>
users::users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::users)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose,false);
}

QHash <QString,QString>users:: hash;

bool users::isTrue(QString username, QString password){
    if(hash.contains(username)){
            QString t=hash.value(username);
            if(t==password){
                return true;
            }
        }
        return false;
}

void users::addUser(QString name,QString psd){
        hash.insert(name,psd);
        emit addUsers(name);
}

users::~users()
{
    delete ui;
}

void users::on_pushButton_clicked()
{
    QString name=ui->lineEdit->text();
    QString psd=ui->lineEdit_2->text();
    if(name.isEmpty()){
        QMessageBox::warning(this,"警告","用户名不能为空!!!",
        QMessageBox::Yes);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
    }else if(psd.isEmpty()){
        QMessageBox::warning(this,"警告","密码不能为空!!!",
        QMessageBox::Yes);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
    }else if(hash.contains(name)){
        QMessageBox::warning(this,"警告","此用户名已被注册!!!",
        QMessageBox::Yes);
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
    }else{
        addUser(name,psd);
        QMessageBox::information(this,"提示","注册成功.");
        this->hide();
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
    }
}

void users::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}
