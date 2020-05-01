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
    //結果格納ベクタをリセット
    url_arr.clear();
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
