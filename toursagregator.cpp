#include "toursagregator.h"

const std::pair<int, int> &ToursAgregator::getStart() const
{
    return start;
}

void ToursAgregator::setStart(const std::pair<int, int> &newStart)
{
    if (start == newStart)
        return;
    start = newStart;
    emit startChanged();
}

ToursAgregator::ToursAgregator()
{
    tour = new TourFinder();
}

ToursAgregator::~ToursAgregator()
{
    delete tour;
}

int ToursAgregator::getResultsCount() const
{
    return tour->getResultsCount();
}

int ToursAgregator::getResultsValueAt(const int index) const
{
    return currentResult.at(index);
}

int ToursAgregator::nextResult()
{
    if(current<tour->getResultsCount()){
        current++;
        currentResult = tour->getResult(current);
    }
    return current;
}

int ToursAgregator::prevResult()
{
    if(current>0){
        current--;
        currentResult = tour->getResult(current);
    }
    return current;
}

void ToursAgregator::find()
{
    tour->pathFinder(start, 1);
}

int ToursAgregator::getSize() const
{
    return tour->getSize();
}

void ToursAgregator::setSize(int newSize)
{
    tour->setSize(newSize);
}
