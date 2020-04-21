#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  this->update();
}

void MainWindow::update()
{

  int rNum, gNum, bNum;

  //setting color to the left rect
  ui->resultColor->setStyleSheet("background-color: rgb("
                                 + ui->rEdit->toPlainText().trimmed() +","
                                 + ui->gEdit->toPlainText().trimmed() +","
                                 + ui->bEdit->toPlainText().trimmed() +");");

  ui->rLabel->setStyleSheet("background-color: rgb(" + ui->rEdit->toPlainText().trimmed() + ",0,0); border: 1px solid #555; border-radius: 10px;");
  ui->gLabel->setStyleSheet("background-color: rgb( 0," + ui->gEdit->toPlainText().trimmed()  + ",0); border: 1px solid #555; border-radius: 10px;");
  ui->bLabel->setStyleSheet("background-color: rgb(0,0," + ui->bEdit->toPlainText().trimmed()  +"); border: 1px solid #555; border-radius: 10px;");

  //counting contrast color parameters
  rNum = 255 - ui->rEdit->toPlainText().trimmed().toInt();
  gNum = 255 - ui->gEdit->toPlainText().trimmed().toInt();
  bNum = 255 - ui->bEdit->toPlainText().trimmed().toInt();

  //setting color to the right rect
  ui->contraColor->setStyleSheet("background-color: rgb("
                                 + QString::number(rNum) +","
                                 + QString::number(gNum) +","
                                 + QString::number(bNum) +")");

  //setting color to the right parameters
  ui->rContra->setStyleSheet("background-color: rgb(" + QString::number(rNum) + ",0,0); border: 1px solid #555; border-radius: 10px;");
  ui->gContra->setStyleSheet("background-color: rgb( 0," + QString::number(gNum)  + ",0); border: 1px solid #555; border-radius: 10px;");
  ui->bContra->setStyleSheet("background-color: rgb(0,0," + QString::number(bNum)  +"); border: 1px solid #555; border-radius: 10px;");

  ui->rContra->setText("R: " + QString::number(rNum));
  ui->gContra->setText("G: " + QString::number(gNum));
  ui->bContra->setText("B: " + QString::number(bNum));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_rEdit_textChanged()
{
    this->update();
}

void MainWindow::on_gEdit_textChanged()
{
    this->update();
}

void MainWindow::on_bEdit_textChanged()
{
    this->update();
}
