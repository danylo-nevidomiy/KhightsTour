#include "dimensionslist.h"

const QString &DimensionsList::text() const
{
    return m_text;
}

void DimensionsList::setText(const QString &newText)
{
    if (m_text == newText)
        return;
    m_text = newText;
    emit textChanged();
}

DimensionsList::DimensionsList()
{
    qDebug() << "DimensionsList::DimensionsList()";
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
    qDebug() << "index.row() = " << index.row();
    qDebug() << "dim[i] = " << m_dimensions[index.row()];
    return QVariant(m_dimensions[index.row()]);
}
