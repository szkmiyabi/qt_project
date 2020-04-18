#include "myclass.h"

MyClass::MyClass(QObject *parent) : QObject(parent) {
}

void MyClass::doSomething() {
    //以下の処理はエラー出てコンパイルできない
    //QMessageBox::information(this, "Hello", "Button has been clicked!");
    messageBox("Hello", "Button has been clicked!");
}

//QMessageBoxのラッパー静的クラスメソッド実装
void MyClass::messageBox(const QString &title, const QString &message_text) {
    QMessageBox msg;
    msg.setWindowTitle(title);
    msg.setText(message_text);
    msg.setIcon(QMessageBox::Information);
    msg.exec();
}
