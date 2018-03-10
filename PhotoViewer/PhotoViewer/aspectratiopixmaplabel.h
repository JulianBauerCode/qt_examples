#ifndef ASPECTRATIOPIXMAPLABEL_H
#define ASPECTRATIOPIXMAPLABEL_H

#ifndef UNUSED
#define UNUSED(p) ( (void)(p) )
#endif

#include <QLabel>
#include <QPixmap>
#include <QResizeEvent>

// =================================================================================================

class AspectRatioPixmapLabel : public QLabel
{
  Q_OBJECT

public:
  explicit AspectRatioPixmapLabel(QWidget *parent = 0);
  virtual int height2width(int width) const;
  virtual QSize sizeHint() const;
  QPixmap scaledPixmap() const;

public slots:
  void setPixmap(const QPixmap &);
  void resizeEvent(QResizeEvent *);

private:
  QPixmap m_data;
};

// =================================================================================================

#endif // ASPECTRATIOPIXMAPLABEL_H
