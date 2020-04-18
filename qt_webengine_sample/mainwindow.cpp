#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //webengineのセットアップ
    webview = new QWebEngineView;
    ui->horizontalLayout_2->addWidget(webview);
    connect(webview, &QWebEngineView::loadProgress, this, &MainWindow::loading);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Webページの読み込み関数の実装
void MainWindow::loadUrl()
{
    QUrl url = QUrl(ui->address->text());
    url.setScheme("http");
    webview->page()->load(url);
}

//progressBar制御のためのスロット実装
void MainWindow::loading(int progress)
{
    ui->progressBar->setValue(progress);
}

//各フォームコントロールのスロット実装
void MainWindow::on_goButton_clicked()
{
    loadUrl();
}

void MainWindow::on_prevButton_clicked()
{
    webview->back();
}

void MainWindow::on_nextButton_clicked()
{
    webview->forward();
}

void MainWindow::on_address_returnPressed()
{
    loadUrl();
}
