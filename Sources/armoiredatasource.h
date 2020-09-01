#ifndef ARMOIREDATASOURCE_H
#define ARMOIREDATASOURCE_H

#include <QDebug>
#include "ncreportdatasource.h"

struct ArmoireData {
    int ID;
    QString Designation;
    QString Type;
    float CosPhi;
    float Pi;
    float Qi;
    float Pu;
    float Qu;
};

class ArmoireDataSource : public NCReportDataSource
{
    Q_OBJECT
public:
    ArmoireDataSource(QObject * parent = 0);
    ~ArmoireDataSource();

    void addData(const ArmoireData&);

    bool open();
    bool close();
    bool first();
    bool last();
    bool next();
    bool previous();
    int size() const;
    QVariant value(const QString& columnname, bool * ok = 0, int nQTDataRole=-1) const;
    QVariant value(int column, bool *ok=0, int nQTDataRole=-1)const;
    bool read(NCReportXMLReader *);
    bool write(NCReportXMLWriter *);
    void evaluate(NCReportEvaluator *evaluator);
    bool hasNext();
    bool seek(int index);
    bool isValid()const;
    int columnIndexByName(const QString& columnname) const;


private:
    QList<ArmoireData> list;

};

#endif // ARMOIREDATASOURCE_H
