#ifndef DIMENSIONSLIST_H
#define DIMENSIONSLIST_H

//#include <QObject>
#include <QAbstractListModel>


class DimensionsList : public QAbstractListModel
{
    Q_OBJECT
    static constexpr int m_defaultDimension = 5;
    static constexpr int m_dimensionsCount = 16;
    static constexpr int m_dimensions[m_dimensionsCount] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

public:
    DimensionsList();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // DIMENSIONSLIST_H
