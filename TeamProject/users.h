#ifndef USERS_H
#define USERS_H

#include <QDialog>

namespace Ui {
class users;
}

class users : public QDialog
{
    Q_OBJECT

public:
    explicit users(QWidget *parent = 0);
    ~users();
    static bool isTrue(QString username, QString password);
    void addUser(QString name,QString psd);
    static QHash <QString,QString> hash;
signals:
    void addUsers(const QString &);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::users *ui;
};

#endif // USERS_H
