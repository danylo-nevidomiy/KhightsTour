#include "agregatorgetter.h"

AgregatorGetter::AgregatorGetter(QObject *object) : QObject(object)
{

}

ToursAgregator *AgregatorGetter::getBoard()
{
    return &agregator;
}

DimensionsList *AgregatorGetter::getDimensions()
{
    qDebug() << "*AgregatorGetter::getDimensions()";
    return &list;
}
