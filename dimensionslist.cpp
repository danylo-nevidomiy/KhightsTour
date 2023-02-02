#include "dimensionslist.h"

DimensionsList::DimensionsList()
{

}

int DimensionsList::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_dimensionsCount;
}

QVariant DimensionsList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant(m_defaultDimension);
    }
    return QVariant(m_dimensions[index.row()]);
}
