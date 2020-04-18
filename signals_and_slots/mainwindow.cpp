#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyClass* myclass = new MyClass;
    connect(this, &MainWindow::doNow, myclass, &MyClass::doSomething);
}

MainWindow::~MainWindow()
{
    delete ui;
}


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

void MainWindow::on_comboBox_activated(const QString &arg1)
{

}

void MainWindow::on_comboBox_activated(int index)
{

}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{

}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

}

void MainWindow::on_comboBox_editTextChanged(const QString &arg1)
{

}

void MainWindow::on_comboBox_highlighted(const QString &arg1)
{

}

void MainWindow::on_comboBox_highlighted(int index)
{

}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_lineEdit_editingFinished()
{

}

void MainWindow::on_lineEdit_returnPressed()
{

}

void MainWindow::on_lineEdit_selectionChanged()
{

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{

}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{

}

void MainWindow::on_spinBox_valueChanged(int arg1)
{

}

void MainWindow::on_horizontalSlider_actionTriggered(int action)
{

}

void MainWindow::on_horizontalSlider_rangeChanged(int min, int max)
{

}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{

}

void MainWindow::on_horizontalSlider_sliderPressed()
{

}

void MainWindow::on_horizontalSlider_sliderReleased()
{

}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{

}
