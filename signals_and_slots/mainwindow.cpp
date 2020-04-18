#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyClass* myclass = new MyClass;
    //コンボボックスに値をセット
    initComoboBox();
    connect(this, &MainWindow::doNow, myclass, &MyClass::doSomething);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initComoboBox() {
    //mainwindowのフォームコントロールはuiを参照
    ui->comboBox->addItem("Option One");
    ui->comboBox->addItem("Option Two");
    ui->comboBox->addItem("Option Three");
}

//PushButtonのイベント処理
void MainWindow::on_pushButton_clicked()
{
    //QMessageBox::information(this, "Hello", "Button has been clicked!");
    //emit doNow();
    qDebug() <<"Push button Clicked!";
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    qDebug() <<"Push button clicked!" << checked;
}

void MainWindow::on_pushButton_pressed()
{
    qDebug() <<"Push button pressed!";
}

void MainWindow::on_pushButton_released()
{
    qDebug() <<"Push button released!";
}

void MainWindow::on_pushButton_toggled(bool checked)
{
    qDebug() <<"Push button toggled!" << checked;

}

//ComboBoxのイベント処理
void MainWindow::on_comboBox_activated(const QString &arg1)
{
    qDebug() <<"Combo box activated:" << arg1;
}

void MainWindow::on_comboBox_activated(int index)
{
    qDebug() <<"Combo box activated:" << index;
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    qDebug() <<"Combo box current index changed:" << arg1;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    qDebug() <<"Combo box current index changed:" << index;
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    qDebug() <<"Combo box current text chenged:" << arg1;
}

void MainWindow::on_comboBox_editTextChanged(const QString &arg1)
{
    qDebug() <<"Combo box edit text changed:" << arg1;
}

void MainWindow::on_comboBox_highlighted(const QString &arg1)
{
    qDebug() <<"Combo box highlighted:" << arg1;
}

void MainWindow::on_comboBox_highlighted(int index)
{
    qDebug() <<"Combo box highlighted:" << index;
}

//LienEditのイベント処理
void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    qDebug() <<"Line edit coursor position changed:" << arg1 <<":" << arg2;
}

void MainWindow::on_lineEdit_editingFinished()
{
    qDebug() <<"Line edit editing finished";
}

void MainWindow::on_lineEdit_returnPressed()
{
    qDebug() <<"Line edit return pressed";
}

void MainWindow::on_lineEdit_selectionChanged()
{
    qDebug() <<"Line edit selection changed";
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    qDebug() <<"Line edit text changed:" << arg1;
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    qDebug() <<"Line edit text edited:" << arg1;
}

//SpinBoxのイベント処理
void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    qDebug() <<"Spin box value changed:" << arg1;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    qDebug() <<"Spin box value changed:" << arg1;
}

//Sliderのイベント処理
void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
    qDebug() <<"Slider action triggered" << action;
}

void MainWindow::on_horizontalSlider_rangeChanged(int min, int max)
{
    qDebug() <<"Slider range changed:" <<"min: " << min <<":, max: " << max;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    qDebug() <<"Slider moved." << position;
}

void MainWindow::on_horizontalSlider_sliderPressed()
{
    qDebug() <<"Slider pressed";
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    qDebug() <<"Slider released";
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug() <<"Slider value chenged:" << value;
}
