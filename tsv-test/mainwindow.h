#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();     //pushButtonクリック

private:
    Ui::MainWindow *ui;

    QVector<QVector<QString>> url_arr;   //結果格納配列

    QString get_file_path();           //ファイルパス取得
    void read_tsv_file();              //TSVファイルの処理

};
#endif // MAINWINDOW_H
