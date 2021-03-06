/****************************************************************************
* 
*  Copyright (C) 2002-2008 Helta Kft. / NociSoft Software Solutions
*  All rights reserved.
*  Author: Norbert Szabo
*  E-mail: nszabo@helta.hu, info@nocisoft.com
*  Web: www.nocisoft.com
* 
*  This file is part of the NCReport reporting software
* 
*  Licensees holding a valid NCReport License Agreement may use this
*  file in accordance with the rights, responsibilities, and obligations
*  contained therein. Please consult your licensing agreement or contact
*  nszabo@helta.hu if any conditions of this licensing are not clear
*  to you.
* 
*  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
*  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
****************************************************************************/
#ifndef NCREPORTTXTDATASOURCE_H
#define NCREPORTTXTDATASOURCE_H

#include "ncreportdatasource.h"
#include <QStringList>

QT_BEGIN_NAMESPACE
class QFile;
class QTextStream;
QT_END_NAMESPACE
/*!
Datasource for QString based texts. Each rows represent a record and the data columns are separated by
a delimiter character.
Inherits: NCReportDataSource
 */
class NCReportTXTDataSource : public NCReportDataSource
{
	Q_OBJECT
public:
	NCReportTXTDataSource( QObject *parent=0 );
	~NCReportTXTDataSource();
	
	enum Delimiter { Tab=0, Comma, SemiColon, Space, VBar, Custom };
	
	bool open();
	bool close();
	bool first();
	bool last();
	bool next();
	bool previous();
	int size() const;
	QVariant value( const QString&, bool* ok=0, int nQTDataRole = -1 ) const;
	QVariant value( int, bool* ok=0, int nQTDataRole = -1 ) const;
	bool read( NCReportXMLReader* );
	bool write( NCReportXMLWriter* );
    void evaluate( NCReportEvaluator* evaluator);
	void setColumnDelimiter( const Delimiter );
	Delimiter columnDelimiter() const;
	void setCustomDelimiterCharacter( const char );
	char delimiterCharacter() const;
	bool seek( int index );

	int rowCount() const;
	int columnCount() const;
	bool hasNext();

	void setHasColumnHeader( bool );
	bool hasColumnHeader() const;
	QStringList keywordList();
	QStringList columnNames();
	QString columnName(int column) const;
	bool isValid() const;
	int columnIndexByName(const QString& columnname) const;

private:
	char delimiter;
	Delimiter cDelim;
	QFile *dataFile;
	QTextStream *ts;
	//QString currentRow;
	//QString lastRow;
	//QString nextRow;
	bool m_hasColumnHeader;
	QStringList m_columns;
	QStringList m_rows;

	bool openStream();
	void closeStream();
	void initColumns();
};


#endif
