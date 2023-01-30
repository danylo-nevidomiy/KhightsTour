#include "agregatorgetter.h"

AgregatorGetter::AgregatorGetter(QObject *object) : QObject(object)
{

}

ToursAgregator *AgregatorGetter::getBoard()
{
    return &agregator;
}
