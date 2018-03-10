#include "aspectratiopixmaplabel.h"
#include <QDebug>

// =================================================================================================

AspectRatioPixmapLabel::AspectRatioPixmapLabel(QWidget *parent)
: QLabel(parent)
{
  this->setMinimumSize(1,1);
  setScaledContents(false);
}

// =================================================================================================

void AspectRatioPixmapLabel::setPixmap (const QPixmap &pixmap)
{
  m_data = pixmap;
  QLabel::setPixmap(scaledPixmap());
}

// =================================================================================================

int AspectRatioPixmapLabel::height2width(int width) const
{
  return m_data.isNull() ? this->height() : ((qreal)m_data.height()*width)/m_data.width();
}

// =================================================================================================

QSize AspectRatioPixmapLabel::sizeHint() const
{
  int w = this->width();
  return QSize(w, height2width(w));
}

// =================================================================================================

QPixmap AspectRatioPixmapLabel::scaledPixmap() const
{
  return m_data.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

// =================================================================================================

void AspectRatioPixmapLabel::resizeEvent(QResizeEvent * e)
{
  UNUSED(e);

  if( ! m_data.isNull() ) QLabel::setPixmap(scaledPixmap());
}

// =================================================================================================
