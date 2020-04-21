#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  void update();
  ~MainWindow();

private slots:

  void on_rEdit_textChanged();

  void on_gEdit_textChanged();

  void on_bEdit_textChanged();

private:
  Ui::MainWindow *ui;
  bool close;

};

#endif // MAINWINDOW_H
