#ifndef IMAGELISTMODEL_H
#define IMAGELISTMODEL_H

#include <QAbstractListModel>
#include <QPixmap>

// =================================================================================================

struct PixmapPair
{
  QString fname;
  QPixmap thumbnail;
};

// =================================================================================================

class ImageListModel : public QAbstractListModel
{
  Q_OBJECT

public:
  enum Roles
  {
    LargePixmapRole = Qt::UserRole + 1
  };

  explicit ImageListModel(QObject *parent = 0);
  virtual ~ImageListModel();

public:
  int rowCount(const QModelIndex &parent) const;
  QVariant data(const QModelIndex &index, int role) const;
  void addFiles(QStringList files);

private:
  QList<PixmapPair*> m_data;
};

// =================================================================================================

#endif // IMAGELISTMODEL_H
