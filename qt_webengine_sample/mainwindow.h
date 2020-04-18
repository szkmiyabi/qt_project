#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QtWebEngineWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //webページの読み込み関数
    void loadUrl();

private slots:
    //各フォームコントロールのスロット登録
    void on_goButton_clicked();
    void on_prevButton_clicked();
    void on_nextButton_clicked();
    void on_address_returnPressed();

    //progressBar制御のためのスロット登録
    void loading(int progress);


private:
    Ui::MainWindow *ui;

    //QWebEngineViewのインスタンス変数を登録
    QWebEngineView* webview;
};
#endif // MAINWINDOW_H
