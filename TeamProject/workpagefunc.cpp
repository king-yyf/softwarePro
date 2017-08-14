#include "workpage.h"
#include "ui_workpage.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QFontDialog>
#include "admin.h"
void WorkPage::initApp(bool isInit){
    ui->lcdNumber->setVisible(false);
    ui->frame_2->setVisible(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    ui->pushButton_31->setEnabled(false);
    ui->pushButton_32->setEnabled(false);
    ui->pushButton_33->setEnabled(false);
    if(Admin::isMatched(userName,"任务1.1")){
        ui->pushButton_10->setEnabled(true);
    }
    if(Admin::isMatched(userName,"任务2.1")){
        ui->pushButton_31->setEnabled(true);
    }
    if(isInit){
        QPalette p;
        QFont f;
        ui->lcdNumber->display(0);
        ui->lcdNumber->setPalette(p);
        ui->lineEdit->setReadOnly(true);
        ui->lineEdit->setText("");
        ui->lineEdit->setPalette(p);
        ui->lineEdit->setFont(f);
        ui->pushButton_11->setStyleSheet("");
        ui->pushButton_12->setStyleSheet("");
        ui->pushButton_32->setStyleSheet("");
        ui->pushButton_33->setStyleSheet("");
    }
}

void WorkPage::timerEvent(QTimerEvent *){
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

QString WorkPage::getName(){
    return userName;
}

void WorkPage::on_actionAbout_triggered()
{
    QMessageBox::about(this,"关于","设计组成员：\n杨云飞，舒亚芸，郭威龙");
}

void WorkPage::on_actionClose_triggered()
{
    this->close();
}

void WorkPage::on_actionHelp_triggered()
{
    QString t=Admin::taskState;
    if(t.isEmpty()){
        QMessageBox::information(this,"帮助","尚未进行任务分配!!!"
                                          );
    }else{
        QMessageBox::information(this,"帮助",t
                                          );
    }
}


void WorkPage::on_action_2_triggered()
{
    if(ui->action_2->isChecked()){
        ui->listWidget->setStyleSheet("");
    }else{
        ui->listWidget->setStyleSheet("background-image: url(:/images/设置1.png)");
    }
}

void WorkPage::on_action_3_triggered()
{
    if(ui->action_3->isChecked()){
        ui->stackedWidget->setStyleSheet("");
    }else{
        ui->stackedWidget->setStyleSheet("background-image: url(:/images/woodbackground.png)");
    }

}


void WorkPage::on_actionuser_triggered()
{
    QString time=QDateTime::currentDateTime().toString();
    QMessageBox::information(this,"欢迎","欢迎你: "+userName+
                                       "\n当前时间为：\n"
                                       +time+" !"
                                      );
}

void WorkPage::on_action_T_triggered()
{
    if(ui->action_T->isChecked()){
        ui->toolBar->setStyleSheet("");
    }else{
        ui->toolBar->setStyleSheet("background-image: url(:/images/woodbackground.png)");
    }
}

void WorkPage::on_actionCllor_triggered()
{
    QColor c=QColorDialog::getColor(Qt::blue);
    if(c.isValid()){
        QMessageBox::warning(this,"警告","你尚未选择编辑内容，请使用其他功能!!!",
        QMessageBox::Yes);//颜色设置
    }
}

void WorkPage::on_actionFont_triggered()
{
    bool ok;
    QFont f=QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10), this);
    if(ok){
      //
        QMessageBox::warning(this,"警告","你尚未选择编辑内容，请使用其他功能!!!",
        QMessageBox::Yes);//颜色设置;//this->mouseGrabber()
    }
}


void WorkPage::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void WorkPage::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void WorkPage::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void WorkPage::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void WorkPage::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void WorkPage::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void WorkPage::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void WorkPage::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void WorkPage::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void WorkPage::on_pushButton_13_clicked()
{
    number.append(ui->pushButton_13->text());
}

void WorkPage::on_pushButton_14_clicked()
{
    number.append(ui->pushButton_14->text());
}

void WorkPage::on_pushButton_15_clicked()
{
    number.append(ui->pushButton_15->text());
}

void WorkPage::on_pushButton_16_clicked()
{
    number.append(ui->pushButton_16->text());
}

void WorkPage::on_pushButton_17_clicked()
{
    number.append(ui->pushButton_17->text());
}

void WorkPage::on_pushButton_18_clicked()
{
    number.append(ui->pushButton_18->text());
}

void WorkPage::on_pushButton_25_clicked()
{
    number.append(ui->pushButton_25->text());
}

void WorkPage::on_pushButton_26_clicked()
{
    number.append(ui->pushButton_26->text());
}

void WorkPage::on_pushButton_27_clicked()
{
    number.append(ui->pushButton_27->text());
}

void WorkPage::on_pushButton_28_clicked()
{
    number.append(ui->pushButton_28->text());
}

void WorkPage::on_pushButton_29_clicked()
{
    if(number.isEmpty()){
        number.append("0"+number.append(ui->pushButton_29->text()));
    }else{
        number.append(ui->pushButton_29->text());
    }
}

void WorkPage::on_pushButton_30_clicked()
{
    bool ok;
    double num=number.toDouble(&ok);
    if(ok){
        ui->lcdNumber->display(num);
        ui->frame_2->setVisible(false);
        emit notify12(number);
    }else{
        QMessageBox::warning(this,"警告","输入错误!!!",
        QMessageBox::Yes);
    }
}

void WorkPage::setwidgets(){
    ui->stackedWidget->setCurrentIndex(0);  //初始时显示的页面
}
