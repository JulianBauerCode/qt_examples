#include "imagelistmodel.h"

// =================================================================================================

ImageListModel::ImageListModel(QObject *parent) : QAbstractListModel(parent)
{
}

// =================================================================================================

void ImageListModel::addFiles(QStringList files)
{
  int N = m_data.count();

  for ( auto iter = files.begin(); iter != files.end(); ++iter)
  {
    QPixmap pix(*iter);
    PixmapPair *pair = new PixmapPair();
    pair->fname      = *iter;
    pair->thumbnail  = pix.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    m_data.append(pair);
  }

  emit dataChanged(this->index(N-1), this->index(N+files.count()-1));
}

// =================================================================================================

ImageListModel::~ImageListModel()
{
  qDeleteAll(m_data);
}

// =================================================================================================

int ImageListModel::rowCount(const QModelIndex &parent) const
{
  if (parent.isValid()) return 0;

  return m_data.count();
}

// =================================================================================================

QVariant ImageListModel::data(const QModelIndex &index, int role) const
{
  if (index.isValid())
  {
    switch (role)
    {
      case Qt::DecorationRole:
        return m_data.value(index.row())->thumbnail;
      case Qt::DisplayRole:
        return m_data.value(index.row())->fname;
      case LargePixmapRole:
        return QPixmap(m_data.value(index.row())->fname);
    }
  }

  return QVariant();
}

// =================================================================================================
