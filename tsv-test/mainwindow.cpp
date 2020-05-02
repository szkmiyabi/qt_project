#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//pushButtonクリック
void MainWindow::on_pushButton_clicked()
{
    read_tsv_file();
    end_open();
}

//Combobox値変更
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    browse_by_urlcombo(index);
}

//テキストファイルのパス取得
QString MainWindow::get_file_path()
{
    QString path = QCoreApplication::applicationDirPath();
    QString filepath = QFileDialog::getOpenFileName(
                        this,
                        tr(u8"ファイルを選択してください"), //u8はMSVC文字化け対策
                        path,
                        tr(u8"tsv file(*.txt)")
    );
    return  filepath;
}



//TSVファイルの処理
void MainWindow::read_tsv_file()
{
    if(url_arr.size() > 0) {
        url_arr.clear();
        ui->comboBox->clear();
    }

    //ファイルパス取得
    QString filename = get_file_path();
    if(filename.size() == 0) return;

    //ファイルオブジェクト取得
    QFile fp(filename);
    if(!fp.open(QIODevice::ReadOnly)) return;

    //テキストストリームを取得
    QTextStream sr(&fp);

    //最終行まで1行づつ読み込む
    while(!sr.atEnd()) {
        QString line = sr.readLine(0);
        QList<QString> tmp = line.split("\t");
        QVector<QString> row;
        row.append(tmp[0]);
        row.append(tmp[1]);
        url_arr.append(row);
    }

    //ファイルオブジェクト破棄
    fp.close();

    //Debug出力
    foreach(const QVector<QString>& row, url_arr){
        QString pid = row.at(0);
        QString url = row.at(1);
        qDebug() <<"pid: " <<pid <<", url: " <<url;
    }

}

//TSVファイルを開いた後の処理
void MainWindow::end_open()
{
    arr_index = 0;
    foreach(const QVector<QString>& row, url_arr) {
        ui->comboBox->addItem(row.at(0));
    }
    QVector<QString> row = url_arr.at(0);
    ui->lineEdit->setText(row[1]);
    ui->comboBox->setCurrentIndex(0);
}


//Comboboxで選択した項目に切り換える
void MainWindow::browse_by_urlcombo(const int& idx)
{
    //TSVファイルを再読み込みした場合スロットが反応するのを阻止
    if(url_arr.size()==0) return;
    arr_index = idx;
    const QVector<QString>& row = url_arr.at(idx);
    ui->lineEdit->setText(row[1]);
}

















