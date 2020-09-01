#ifndef FILSDATASOURCE_H
#define FILSDATASOURCE_H

#include <QDebug>
#include "ncreportdatasource.h"

struct FilsData {
    int ID;
    QString DesignationDuParent;
    QString TypeDuParent;
    float CosphiP;
    float PiP;
    float QiP;
    float PuP;
    float QuP;
    QString Designation;
    QString Type;
    float CosPhi;
    float Pi;
    float Qi;
    float Pu;
    float Qu;    
};

class FilsDataSource : public NCReportDataSource
{
    Q_OBJECT
public:
    FilsDataSource(QObject * parent = 0);
    ~FilsDataSource();

    void addData(const FilsData&);

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
    QList<FilsData> list;

};

#endif // FILSDATASOURCE_H
