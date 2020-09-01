/***************************************************************************
 *   Copyright (C) 2010 by NociSoft Software Solutions
 *   support@nocisoft.com
 ***************************************************************************/
#ifndef NCREPORTHTMLOUTPUT_H
#define NCREPORTHTMLOUTPUT_H

#include "ncreportoutput.h"

#include <QTextStream>
#include <QMultiMap>
#include <QHash>

QT_BEGIN_NAMESPACE
class QFile;
QT_END_NAMESPACE

class NCReportItem;
class NCReportLabelItem;
class NCReportLineItem;
class NCReportRectItem;
class NCReportImageItem;
class NCReportTextItem;
class NCReportBarcodeItem;

/*!
Html Output class. Result pages are stored in one .html file
*/
class NCREPORTSHARED_EXPORT NCReportHtmlOutput : public NCReportOutput
{
    Q_OBJECT
public:
    NCReportHtmlOutput( QObject* parent=0 );
    ~NCReportHtmlOutput();

    enum HtmlStrategy { SectionOneTable=0, SectionMultiTables };

    bool setup();
    void cleanup();
    void begin();
    void end();
    void newPage();

    virtual void renderItem( NCReportItem* item, const QRectF& rect );
    static QByteArray imageToHtml(const QPixmap& image , const QSize &size = QSize() );
    void setStrategy( HtmlStrategy strategy );
    HtmlStrategy strategy() const;
    void setStyleSheetFile( const QString& cssFile );
    QString styleSheetFile() const;

protected:
    void writeLabel(NCReportLabelItem *item , QTextStream &tsStyle);
    void writeLine( NCReportLineItem *item );
    void writeRectangle( NCReportRectItem * item );
    void writeImage( NCReportImageItem * item );
    void writeText( NCReportTextItem * item );
    void writeBarcode( NCReportBarcodeItem* item);

    void sectionStarts(NCReportSection *section, NCReportEvaluator *evaluator);
    void sectionEnds(NCReportSection *section, NCReportEvaluator *evaluator);

private:
    void writeHeader();
    void writeFooter();
    QString penStyleName( int style ) const;

    void writeItem(NCReportItem* item);
    void writeSpacing(NCReportSection *section, int row, int width );
    void writeSectionStart( const QString& sectionID );
    void writeSectionEnd( const QString& sectionID );
    void initStyleStream( QTextStream& styleStream, const QString& classID );
    void cleanHtml( QString& html );
    void writeDocumentFormats();

private:
    QFile* m_file;
    int m_pagePos;
    QByteArray m_crlf;
    QString m_sectionID;
    bool m_initalState;
    int m_rowCounter;
    HtmlStrategy m_strategy;
    QString m_cssFile;

    QMultiMap<int,NCReportItem*> m_sectionItems;
    QHash<QString,QString> m_styleClasses;

    QString m_html;
    QString m_style;

    QTextStream m_tsHtml;
    QTextStream m_tsStyle;
};


#endif // NCREPORTHTMLOUTPUT_H
