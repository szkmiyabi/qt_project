#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QMainWindow>
#include <QMessageBox>

class MyClass : public QObject
{
    Q_OBJECT
private:
    //QMessageBoxのラッパー静的クラスメソッド
    void messageBox(const QString& title, const QString& message_text);

public:
    explicit MyClass(QObject *parent = nullptr);

signals:

public slots:
    void doSomething();
};

#endif // MYCLASS_H
