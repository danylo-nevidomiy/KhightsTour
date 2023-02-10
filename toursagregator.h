#ifndef TOURSAGREGATOR_H
#define TOURSAGREGATOR_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <set>
#include <QString>

#include "tourfinder.h"
#include "queuedispatcher.h"
#include "board.h"

class ToursAgregator : public QAbstractListModel
{
    Q_OBJECT
    Board* board;

    std::set<int> highlightedCells;
    QueueDispatcher dispatcher;

public:
    ToursAgregator();
    ToursAgregator(int n);
    ~ToursAgregator();

    void takeStep() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;




    Q_INVOKABLE int getResultsCount() const;
//    Q_INVOKABLE int getResultsValueAt(const int index) const;
    Q_INVOKABLE int nextResult();
    Q_INVOKABLE int prevResult();
    Q_INVOKABLE bool hasNextResult() const;
    Q_INVOKABLE bool hasPrevResult() const;
    Q_INVOKABLE void find();
    Q_INVOKABLE int size() const;
    Q_INVOKABLE void setSize(int newSize);
    int cellsCount() const;
    void setCellsCount(int newCellsCount);
    void updateCurrentStates();
    Q_INVOKABLE void step(int index);
    Q_INVOKABLE void clear();
    Q_INVOKABLE void forward();
    Q_INVOKABLE void back();
    Q_INVOKABLE bool isHighlighted(int n) const;

    const QList<int> &dimensions() const;

signals:

    void victory();
    void highlightedCellsChanged();
    void hasNextResultChanged(bool);
    void hasPrevResultChanged(bool);
    void resultCountChanged(int);
    void sizeChanged(int);
};

#endif // TOURSAGREGATOR_H
