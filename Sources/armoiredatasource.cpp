#include "armoiredatasource.h"
#include "ncreportdef.h"

ArmoireDataSource::ArmoireDataSource(QObject *parent) : NCReportDataSource(parent)
{
    datasourcetype = Custom;
    location = Static;
    recno = 0;
}

ArmoireDataSource::~ArmoireDataSource()
{

}

bool ArmoireDataSource::open()
{    
    if(list.empty()){
        error->setError(tr("No data in ArmoireDataSource datasource"));
        return false;
    }

    recno=0;
    m_opened = true;
    return true;
}

bool ArmoireDataSource::close()
{
    recno =0;
    m_opened = false;
    return true;
}

bool ArmoireDataSource::next()
{
    recno++;

    if(recno >= list.count())
    {
        recno--;
        flagEnd = true;
        return FALSE;
    }

    flagBegin = false;
    return TRUE;
}

bool ArmoireDataSource::hasNext()
{
    return (recno<list.count()-1);
}

bool ArmoireDataSource::seek(int index)
{
    bool ok=true;
    if ( index == -1 )
            recno =0;
    else if ( index < list.count())
            recno = index;
    else
    {
            recno = list.count()-1;
            ok=false;
    }

    return ok;
}

int ArmoireDataSource::size() const
{
    return list.count();
}

bool ArmoireDataSource::previous()
{
    recno--;

    if( recno <= 0 ) {
        recno = 0;
        flagBegin = true;
        return FALSE;
    }

    flagEnd = false;
    return TRUE;
}

bool ArmoireDataSource::first()
{
    recno = 0;
    return TRUE;
}

bool ArmoireDataSource::last()
{
    recno = list.count()-1;
    return TRUE;
}

QVariant ArmoireDataSource::value(const QString &column, bool *ok, int i) const
{    
    int col = columnIndexByName(column);
    if (col<0) {
            *ok = false;
            return QVariant();
    }
    return value( col, ok, i );
}

QVariant ArmoireDataSource::value(int column, bool *ok, int nQTDataRole) const
{
    QVariant v;
    switch (column)
    {
    case 0: v = list.at(recno).ID;
        break;
    case 1: v = list.at(recno).Designation;
        break;
    case 2: v = list.at(recno).Type;
        break;
    case 3: v = list.at(recno).CosPhi;
        break;
    case 4: v = list.at(recno).Pi;
        break;
    case 5: v = list.at(recno).Qi;
        break;
    case 6: v = list.at(recno).Pu;
        break;
    case 7: v = list.at(recno).Qu;
        break;
    }

    return v;
}

bool ArmoireDataSource::read(NCReportXMLReader *)
{
    return TRUE;
}

bool ArmoireDataSource::write(NCReportXMLWriter *)
{
    return TRUE;
}

void ArmoireDataSource::evaluate(NCReportEvaluator *evaluator)
{

}

void ArmoireDataSource::addData(const ArmoireData & data)
{
    list.append(data);
}

bool ArmoireDataSource::isValid() const
{
    return true;
}

int ArmoireDataSource::columnIndexByName(const QString &columnname) const
{
    if ( columnname == "ID" )
            return 0;
    if ( columnname == "designationdearmoire" )
            return 1;
    if ( columnname == "typedearmoire" )
            return 2;
    if ( columnname == "cosphi_p" )
            return 3;
    if ( columnname == "pi_p" )
            return 4;
    if ( columnname == "qi_p" )
            return 5;
    if ( columnname == "pu_p" )
            return 6;
    if ( columnname == "qu_p" )
            return 7;

    return -1;
}
