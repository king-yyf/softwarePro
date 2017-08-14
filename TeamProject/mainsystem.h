#ifndef MAINSYSTEM_H
#define MAINSYSTEM_H

#include <QMainWindow>
#include "login.h"
#include "workpage.h"
#include <QList>
#include "users.h"
#include "admin.h"
namespace Ui {
class MainSystem;
}

class MainSystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSystem(QWidget *parent = 0);
    ~MainSystem();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void showPage(const QString &);

    void allNotify11(const QString &);//任务一完成后的唤醒观察者槽函数

    void allNotify12(const QString &);

    void allNotify13(const QColor &);

    void allNotify21(const QString &);//项目二任务一

    void allNotify22(const QFont &);

    void allNotify23(const QColor &);

    void reBeginAll();//users

    void updataUser(const QString &);//

private:
    Ui::MainSystem *ui;
    Admin *admin;
    Login *loginPage;
    users *puser;
    QList<WorkPage *> pageList ;
};

#endif // MAINSYSTEM_H
