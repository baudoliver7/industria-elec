#include "filsdatasource.h"
#include "ncreportdef.h"

FilsDataSource::FilsDataSource(QObject *parent) : NCReportDataSource(parent)
{
    datasourcetype = Custom;
    location = Static;
    recno = 0;
}

FilsDataSource::~FilsDataSource()
{

}

bool FilsDataSource::open()
{    
    if(list.empty()){
        error->setError(tr("No data in FilsDataSource datasource"));
        return false;
    }

    recno=0;
    m_opened = true;
    return true;
}

bool FilsDataSource::close()
{
    recno =0;
    m_opened = false;
    return true;
}

bool FilsDataSource::next()
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

bool FilsDataSource::hasNext()
{
    return (recno<list.count()-1);
}

bool FilsDataSource::seek(int index)
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

int FilsDataSource::size() const
{
    return list.count();
}

bool FilsDataSource::previous()
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

bool FilsDataSource::first()
{
    recno = 0;
    return TRUE;
}

bool FilsDataSource::last()
{
    recno = list.count()-1;
    return TRUE;
}

QVariant FilsDataSource::value(const QString &column, bool *ok, int i) const
{    
    int col = columnIndexByName(column);
    if (col<0) {
            *ok = false;
            return QVariant();
    }
    return value( col, ok, i );
}

QVariant FilsDataSource::value(int column, bool *ok, int nQTDataRole) const
{
    QVariant v;
    switch (column)
    {
    case 0: v = list.at(recno).ID;
        break;
    case 1: v = list.at(recno).DesignationDuParent;
        break;
    case 2: v = list.at(recno).TypeDuParent;
        break;
    case 3: v = list.at(recno).CosphiP;
        break;
    case 4: v = list.at(recno).PiP;
        break;
    case 5: v = list.at(recno).QiP;
        break;
    case 6: v = list.at(recno).PuP;
        break;
    case 7: v = list.at(recno).QuP;
        break;
    case 8: v = list.at(recno).Designation;
        break;
    case 9: v = list.at(recno).Type;
        break;
    case 10: v = list.at(recno).CosPhi;
        break;
    case 11: v = list.at(recno).Pi;
        break;
    case 12: v = list.at(recno).Qi;
        break;
    case 13: v = list.at(recno).Pu;
        break;
    case 14: v = list.at(recno).Qu;
        break;
    }

    return v;
}

bool FilsDataSource::read(NCReportXMLReader *)
{
    return TRUE;
}

bool FilsDataSource::write(NCReportXMLWriter *)
{
    return TRUE;
}

void FilsDataSource::evaluate(NCReportEvaluator *evaluator)
{

}

void FilsDataSource::addData(const FilsData & data)
{
    list.append(data);
}

bool FilsDataSource::isValid() const
{
    return true;
}

int FilsDataSource::columnIndexByName(const QString &columnname) const
{
    if ( columnname == "ID" )
            return 0;
    if ( columnname == "designationdeparent" )
            return 1;
    if ( columnname == "typedeparent" )
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
    if ( columnname == "designation" )
            return 8;
    if ( columnname == "type" )
            return 9;
    if ( columnname == "cosphi" )
            return 10;
    if ( columnname == "pi" )
            return 11;
    if ( columnname == "qi" )
            return 12;
    if ( columnname == "pu" )
            return 13;
    if ( columnname == "qu" )
            return 14;

    return -1;
}
