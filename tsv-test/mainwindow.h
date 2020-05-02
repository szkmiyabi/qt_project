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


private:
    Ui::MainWindow *ui;

    QVector<QVector<QString>> url_arr;   //結果格納配列
    int arr_index;                       //配列カウンタ

    QString get_file_path();           //ファイルパス取得
    void read_tsv_file();              //TSVファイルの処理
    void end_open();                    //TSVファイルを開いた後の処理
    //Comboboxで選択した項目に切り換える
    void browse_by_urlcombo(const int& idx);


};
#endif // MAINWINDOW_H
