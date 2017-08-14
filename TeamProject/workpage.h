#ifndef WORKPAGE_H
#define WORKPAGE_H

#include <QMainWindow>
#include <QString>
#include <QList>
namespace Ui {
class WorkPage;
}

class WorkPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkPage(QWidget *parent = 0,QString  userName="");

    void setwidgets();
    QString getName();

    void initApp(bool isinit);
    void updataState();
    void updata12(QString text);
    void updata13(QColor color);
    void updata21(QString args);
    void updata22(QFont font);
    void updata23(QColor color);
    ~WorkPage(); 

signals:
    void notify11(const QString &);        //定义唤醒被观察者的信号，11表示项目一的任务一
    void notify12(const QString &);        //项目一任务二唤醒信号
    void notify13(const QColor &);
    void notify21(const QString &);
    void notify22(const QFont &);
    void notify23(const QColor &);

protected:
    void timerEvent(QTimerEvent *);

private slots:
    void on_actionAbout_triggered();

    void on_actionClose_triggered();

    void on_actionHelp_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_actionuser_triggered();

    void on_action_T_triggered();

    void on_actionCllor_triggered();

    void on_actionFont_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

  //  void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_33_clicked();

    void on_pushButton_32_clicked();

    void on_actionSave_triggered();

    void on_actionFresh_triggered();

   // void on_lineEdit_editingFinished();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_editingFinished();

private:
    Ui::WorkPage *ui;
    QString userName;
    QString number;
    //QList<QString> userList;
};

#endif // WORKPAGE_H
