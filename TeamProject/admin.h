#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QMap>
#include <QList>
namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = 0);
    ~Admin();
    static QMap<QString,QString> workMap;
    static QString taskState; //分配任务的状态
    static bool isMatched(QString name,QString work);
    void addTask(QString user,QString task);
    void setUserBox(QString name);
protected:
    void timerEvent(QTimerEvent *);
signals:
    void reStart();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    void reAssign();//重新分配
    QString displayTask();
    Ui::Admin *ui;
};

#endif // ADMIN_H
