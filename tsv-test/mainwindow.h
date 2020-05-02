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

    void on_comboBox_currentIndexChanged(int index); //combobox値変更

    void on_prevButton_clicked();   //prevButtonクリック

    void on_nextButton_clicked();   //nextButtonクリック

private:
    Ui::MainWindow *ui;

    QVector<QVector<QString>> url_arr;   //結果格納配列
    int arr_index;                       //配列カウンタ

    //ファイルパス取得
    QString get_file_path();
    //TSVファイルの処理
    void read_tsv_file();
    //TSVファイルを開いた後の処理
    void end_open();
    //Comboboxで選択した項目に切り換える
    void browse_by_urlcombo(const int& idx);
    //前のURL
    void browse_prev();
    //次のURL
    void browse_next();


};
#endif // MAINWINDOW_H
