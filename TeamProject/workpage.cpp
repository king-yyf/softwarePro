#include "workpage.h"
#include "ui_workpage.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QFontDialog>
#include <QBrush>
#include "users.h"
#include "admin.h"
WorkPage::WorkPage(QWidget *parent,QString userName) :
    QMainWindow(parent),
    ui(new Ui::WorkPage)
{
    ui->setupUi(this);
    this->userName=userName;
    QFont ft;
    ft.setPointSize(12);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::green);
    ui->userInfo->setText( "  welcome "+userName+"!");
    ui->userInfo->setFont(ft);
    ui->userInfo->setPalette(pa);
    this->setAttribute(Qt::WA_QuitOnClose,false);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    startTimer(5000);

    initApp(false);
}

WorkPage::~WorkPage()
{
    delete ui;
}


void WorkPage::updataState(){
    ui->lcdNumber->setVisible(true);
    if(Admin::isMatched(userName,"任务1.2")){
        ui->pushButton_12->setEnabled(true);
        ui->pushButton_12->setStyleSheet("color: rgb(0, 255, 0)");
    }

    ui->pushButton_10->setEnabled(false);
}

void WorkPage::updata12(QString text){
    bool ok;
    double num=text.toDouble(&ok);
    if(ok){
        ui->lcdNumber->display(num);
    }
    if(Admin::isMatched(userName,"任务1.3")){
        ui->pushButton_11->setEnabled(true);
        ui->pushButton_11->setStyleSheet("color: rgb(0, 255, 0)");
    }
    ui->pushButton_12->setEnabled(false);
    ui->frame_2->setVisible(false);
    ui->pushButton_12->setStyleSheet("");
}

void WorkPage::updata13(QColor color){
    ui->lcdNumber->setPalette(QPalette(color));
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_11->setStyleSheet("");
}

void WorkPage::updata21(QString args){
    ui->lineEdit->setText(args);
    if(Admin::isMatched(userName,"任务2.2")){
        ui->pushButton_33->setEnabled(true);
        ui->pushButton_33->setStyleSheet("color: rgb(0, 255, 0)");
    }
    ui->pushButton_31->setEnabled(false);
    ui->pushButton_31->setStyleSheet("");
}

void WorkPage::updata22(QFont font){
    ui->lineEdit->setFont(font);
    if(Admin::isMatched(userName,"任务2.3")){
        ui->pushButton_32->setEnabled(true);
        ui->pushButton_32->setStyleSheet("color: rgb(0, 255, 0)");
    }
    ui->pushButton_33->setEnabled(false);
    ui->pushButton_33->setStyleSheet("");
}

void WorkPage::updata23(QColor color){
      QPalette palette;
      QBrush brush=QBrush(color,Qt::DiagCrossPattern);
      palette.setBrush(QPalette::Text,  brush);
      ui->lineEdit->setPalette(palette);
      ui->pushButton_32->setEnabled(false);
      ui->pushButton_32->setStyleSheet("");
}

void WorkPage::on_pushButton_10_clicked()
{
    ui->lcdNumber->setVisible(true);
   // ui->pushButton->setEnabled();
    emit notify11(userName);
}

void WorkPage::on_pushButton_11_clicked()
{
    QColor c=QColorDialog::getColor(Qt::blue);
    if(c.isValid()){
        ui->pushButton_11->setStyleSheet("");
        emit notify13(c);
    }
}

void WorkPage::on_pushButton_12_clicked()
{
   ui->frame_2->setVisible(true);
   ui->pushButton_12->setStyleSheet("");
   number="";
}

void WorkPage::on_pushButton_31_clicked()
{
    ui->lineEdit->setReadOnly(false);
}

/*void WorkPage::on_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        emit notify21(arg1);
        //??notify();
    }
}*/

void WorkPage::on_pushButton_33_clicked()
{
    bool ok;
    QFont f=QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10), this);
    if(ok){
        ui->pushButton_33->setStyleSheet("");
        emit notify22(f);
    }
}

void WorkPage::on_pushButton_32_clicked()
{
    QColor c=QColorDialog::getColor(Qt::blue);
    if(c.isValid()){
        ui->pushButton_32->setStyleSheet("");
        emit notify23(c);

    }
}

void WorkPage::on_actionSave_triggered()
{
    QMessageBox::information(this,"项目一","项目一分为三个顺序任务：\n"
                             "1：为创建并显示一个lcd屏幕\n"
                             "2：在lcd数字显示屏上写上一个数字\n"
                             "3：为lcd上显示的数字设置颜色"
                         );
}

void WorkPage::on_actionFresh_triggered()
{
    QMessageBox::information(this,"项目二","项目二分为三个顺序任务：\n"
                             "1：在文本编辑框上写上一个字符串\n"
                             "2：设置字符串的显示字体\n"
                             "3：设置字符串的显示颜色"
                         );
}

void WorkPage::on_lineEdit_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        emit notify21(arg1);
        //??notify();
    }
}

void WorkPage::on_lineEdit_editingFinished()
{
    ui->lineEdit->setReadOnly(true);
}
