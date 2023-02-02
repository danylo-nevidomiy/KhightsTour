#ifndef TOURSVIEWMODEL_H
#define TOURSVIEWMODEL_H

#include <QObject>
#include <QScreen>

#include "toursagregator.h"
#include "dimensionslist.h"

class AgregatorGetter : public QObject
{
    Q_OBJECT
    ToursAgregator agregator;
    DimensionsList list;
public:
    AgregatorGetter(QObject* object = nullptr);
    Q_INVOKABLE ToursAgregator *getBoard();
    Q_INVOKABLE DimensionsList *getDimensions();
};

#endif // TOURSVIEWMODEL_H
