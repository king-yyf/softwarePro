#include "mainsystem.h"
#include "ui_mainsystem.h"
#include <QMessageBox>
MainSystem::MainSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSystem)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose,true);
    loginPage=new Login;
    admin=new Admin;
    puser=new users;

    connect(puser,SIGNAL(addUsers(const QString &)),this,SLOT(updataUser(const QString &)));
    connect(admin,SIGNAL(reStart()),this,SLOT(reBeginAll()));
    connect(loginPage,SIGNAL(sendMsg(const QString &)),this,SLOT(showPage(const QString &)));
}

MainSystem::~MainSystem()
{
    delete ui;
}

void MainSystem::showPage(const QString &name){

    if(name=="admin"){   //判断是否为管理员
        admin->show();
    }
    for(int i=0;i<pageList.length();i++){
       WorkPage *obj=pageList.at(i);
       if(name==obj->getName()){ 
           obj->setwidgets();
           obj->show();
           break;
       }
   }
}

void MainSystem::updataUser(const QString & name){
    admin->setUserBox(name);
    WorkPage *obj=new WorkPage(this,name);
    pageList.append(obj);
    connect(obj,SIGNAL(notify11(const QString &)),this,SLOT(allNotify11(const QString &)));
    connect(obj,SIGNAL(notify12(const QString &)),this,SLOT(allNotify12(const QString &)));
    connect(obj,SIGNAL(notify13(const QColor &)),this,SLOT(allNotify13(const QColor &)));
    connect(obj,SIGNAL(notify21(const QString &)),this,SLOT(allNotify21(const QString &)));
    connect(obj,SIGNAL(notify22(const QFont &)),this,SLOT(allNotify22(const QFont &)));
    connect(obj,SIGNAL(notify23(const QColor &)),this,SLOT(allNotify23(const QColor &)));
}

void MainSystem::allNotify11(const QString &){
    for(int i=0;i<pageList.length();++i){
        WorkPage *obj=pageList.at(i);
        obj->updataState();
    }
}

void MainSystem::allNotify12(const QString & text){
    for(int i=0;i<pageList.length();++i){
        WorkPage *obj=pageList.at(i);
        obj->updata12(text);
    }
}

void MainSystem::allNotify13(const QColor & color){
    for(int i=0;i<pageList.length();++i){
        WorkPage *obj=pageList.at(i);
        obj->updata13(color);
    }
}

void MainSystem::allNotify21(const QString & args){
    for(int i=0;i<pageList.length();++i){
        WorkPage *obj=pageList.at(i);
        obj->updata21(args);
    }
}

void MainSystem::allNotify22(const QFont & font){
    for(int i=0;i<pageList.length();++i){
        WorkPage *obj=pageList.at(i);
        obj->updata22(font);
    }
}


void MainSystem::allNotify23(const QColor & color){
    for(int i=0;i<pageList.length();++i){
        WorkPage *obj=pageList.at(i);
        obj->updata23(color);
    }
}

void MainSystem::on_pushButton_clicked()
{
    loginPage->show();
}

void MainSystem::on_pushButton_2_clicked()
{
    puser->show();
    //loginPage->destroy();
}

void MainSystem::reBeginAll(){
    for(int i=0;i<pageList.length();++i){
        WorkPage *obj=pageList.at(i);
        obj->initApp(true);
        obj->hide();
    }
}
