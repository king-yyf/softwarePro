#include "admin.h"
#include "ui_admin.h"
#include "users.h"
#include <QMessageBox>
Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_QuitOnClose,false);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    startTimer(2000);

}
QMap<QString,QString>Admin:: workMap;
QString Admin::taskState;
Admin::~Admin()
{
    delete ui;
}

void Admin::timerEvent(QTimerEvent *){
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

bool Admin::isMatched(QString name, QString work){    //判断用户和任务是否匹配
    if(workMap.contains(name)){
        QString t=workMap.value(name);
        if(t.contains(work)){
            return true;
        }
    }
    return false;
}

void Admin::addTask(QString user,QString task){
    if(workMap.contains(user)){
        if(!workMap.value(user).contains(task)){
            QString newTask=workMap.value(user)+" "+task;
            workMap.insert(user,newTask);
       }
   }else{
         workMap.insert(user,task);
    }
}

void Admin::on_pushButton_clicked()
{
    QString user=ui->comboBox->currentText();
    QString task=ui->comboBox_2->currentText();
    addTask(user,task);
    ui->plainTextEdit->setPlainText(displayTask());
}

QString Admin::displayTask(){
    QString text;
    QMap<QString, QString>::const_iterator i = workMap.constBegin();
    if(taskState.isEmpty()){
        while (i != workMap.constEnd()) {
            text=text+"用户"+i.key()+"分配的任务为："+i.value()+"\n";
            ++i;
        }
    }
    return text;
}

void Admin::reAssign(){
    workMap.clear();
    taskState="";
}

void Admin::on_pushButton_3_clicked()
{
    reAssign();
    ui->pushButton->setEnabled(true);
    ui->plainTextEdit->setPlainText("");
    emit reStart();
}

void Admin::on_pushButton_2_clicked()
{
    QString content;
    QMap<QString, QString>::const_iterator i = workMap.constBegin();
    if(taskState.isEmpty()){
        while (i != workMap.constEnd()) {
            content="用户"+i.key()+"分配的任务为："+i.value()+"\n";
            taskState.append(content);
            ++i;
        }
    }
    ui->pushButton->setEnabled(false);
    emit reStart();
}

void Admin::setUserBox(QString name){
   // userBox.append(name);
    ui->comboBox->addItem(name);
}

void Admin::on_pushButton_4_clicked()
{
    QString time=QDateTime::currentDateTime().toString();
    QMessageBox::information(this,"欢迎","欢迎你: admin\n当前时间为：\n"
                                       +time+" !"
                                      );
}
