#include "mainwindow.h"
#include "ui_mainwindow.h"

// =================================================================================================

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // create model
  model = new ImageListModel(ui->listView);

  // use "listView" to view the "model"
  ui->listView->setModel(model);

  // allow only one selection at a time in the list
  ui->listView->setSelectionMode(QListView::SingleSelection);

  // selection changed -> show different large image
  connect(
    ui->listView->selectionModel(),
    &QItemSelectionModel::selectionChanged,
    [=](){this->viewSelectedImage();}
  );
}

// =================================================================================================

MainWindow::~MainWindow()
{
  delete ui;
}

// =================================================================================================

void MainWindow::viewSelectedImage()
{
  QModelIndex selectedIndex = ui->listView->selectionModel()->selectedIndexes().first();

  ui->label->setPixmap(selectedIndex.data(ImageListModel::LargePixmapRole).value<QPixmap>());
}

// =================================================================================================

void MainWindow::on_actionOpen_triggered()
{
  // select a folder using a dialog
  // - allocate
  QFileDialog dialog(this);
  // - define dialog
  dialog.setFileMode  (QFileDialog::ExistingFiles);
  dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
  // - run dialog
  if (dialog.exec())
    model->addFiles(dialog.selectedFiles());
}

// =================================================================================================
