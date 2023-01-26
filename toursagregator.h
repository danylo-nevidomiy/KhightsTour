#ifndef TOURSAGREGATOR_H
#define TOURSAGREGATOR_H

#include <QObject>
#include "tourfinder.h"

class ToursAgregator : public QObject
{
    Q_OBJECT
    TourFinder* tour;
    int current = 0;
    std::vector<int> currentResult;
    std::pair<int, int> start = {0,0};
    Q_PROPERTY(std::pair<int, int> start READ getStart WRITE setStart NOTIFY startChanged)

public:
    ToursAgregator();
    ~ToursAgregator();
    Q_INVOKABLE int getResultsCount() const;
    Q_INVOKABLE int getResultsValueAt(const int index) const;
    Q_INVOKABLE int nextResult();
    Q_INVOKABLE int prevResult();
    Q_INVOKABLE void find();
    Q_INVOKABLE int getSize() const;
    Q_INVOKABLE void setSize(int newSize);
    const std::pair<int, int> &getStart() const;
    void setStart(const std::pair<int, int> &newStart);
signals:
    void startChanged();
};

#endif // TOURSAGREGATOR_H
