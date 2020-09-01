#ifndef REPORTWIDGETRENDERER_H
#define REPORTWIDGETRENDERER_H

#include "ncreportabstractitemrendering.h"
#include "ncreport_global.h"
#include <QWidget>

class NCREPORTSHARED_EXPORT NCReportWidgetRenderer : public NCReportAbstractItemRendering
{
public:
	NCReportWidgetRenderer();
	~NCReportWidgetRenderer();

	virtual void paintItem( QPainter* painter, NCReportOutput* output, const QRectF& rect, const QString& itemdata );
	void setWidget(QWidget* p);
	void setScaleMode(Qt::AspectRatioMode mode = Qt::KeepAspectRatioByExpanding);
	virtual qreal calculateHeightMM( NCReportOutput* output ) const;
	virtual QSizeF calculateSizeMM( NCReportOutput* output, const QSizeF& requested ) const;

	void setDPI(unsigned int dpi = -1);
	unsigned int getDPI();

	void setBaseSize(const QSizeF& base = QSizeF());
	QSizeF getBaseSize();

private:
	QWidget* pWidget;
	Qt::AspectRatioMode scaleMode;
	unsigned int resolution;
	QSizeF baseSize;
};

#endif // REPORTWIDGETRENDERER_H
