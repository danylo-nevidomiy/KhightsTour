#ifndef TOURSVIEWMODEL_H
#define TOURSVIEWMODEL_H

#include <QObject>
#include <QScreen>

#include "toursagregator.h"

class AgregatorGetter : public QObject
{
    Q_OBJECT
    ToursAgregator agregator;
public:
    AgregatorGetter(QObject* object = nullptr);
    Q_INVOKABLE ToursAgregator *getBoard();
};

#endif // TOURSVIEWMODEL_H
