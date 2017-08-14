#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
//#include "workpage.h"
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
signals:
    void sendMsg(const QString &);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    //void loginMsg();
private:
    Ui::Login *ui;
    //user users;
 //   WorkPage *workPage;
};

#endif // LOGIN_H
