#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include <QFileDialog>

#include "imagelistmodel.h"

// =================================================================================================

namespace Ui {
class MainWindow;
}

// =================================================================================================

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void viewSelectedImage();
  void on_actionOpen_triggered();

private:
  Ui::MainWindow *ui;
  ImageListModel *model;
};

// =================================================================================================

#endif // MAINWINDOW_H
