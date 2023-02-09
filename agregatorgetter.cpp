#include "agregatorgetter.h"

AgregatorGetter::AgregatorGetter(QObject *object) : QObject(object)
{
    agregator = new ToursAgregator();
}

ToursAgregator *AgregatorGetter::getBoard()
{
    return agregator;
}

DimensionsList *AgregatorGetter::getDimensions()
{
    qDebug() << "*AgregatorGetter::getDimensions()";
    return &list;
}

ToursAgregator *AgregatorGetter::changeBoard(int n)
{
    delete agregator;
    agregator = new ToursAgregator(n);
    return agregator;
}
