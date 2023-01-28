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

ToursAgregator::ToursAgregator() : ToursAgregator(5){}

ToursAgregator::ToursAgregator(int n)
{
    tour = new TourFinder(n);
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
        emit currentChanged(++current+1);
        currentResult = tour->getResult(current);
    }
    updateCurrentStates();
    return current;
}

int ToursAgregator::prevResult()
{
    if(current>0){
        emit currentChanged(--current+1);
        currentResult = tour->getResult(current);
    }
    updateCurrentStates();
    return current;
}

bool ToursAgregator::hasNextResult() const
{
    if(current<tour->getResultsCount()){
        return true;
    }
    return false;
}

bool ToursAgregator::hasPrevResult() const
{
    if(current>0){
        return true;
    }
    return false;
}

void ToursAgregator::find()
{
//    QueueDispatcher& d = dispatcher;
//    TourFinder& t = *tour;
//    ResultHandler handler = [&d, &t](std::vector<int> res){
//        d.dispatchNow([&t](std::vector<int> result){
//            t.saveResultNow(result);
//        });
//    };
    tour->pathFinder(start, 1);
    emit resultCountChanged(tour->getResultsCount());
    current = 0;
    emit currentChanged(current+1);
    updateCurrentStates();

}

int ToursAgregator::getSize() const
{
    return tour->getSize();
}

void ToursAgregator::setSize(int newSize)
{
    tour->setSize(newSize);
    emit sizeChanged(newSize);
}

void ToursAgregator::updateCurrentStates()
{
    if(hasNextResult()){
        emit hasNextResultChanged(true);
    }else{
        emit hasNextResultChanged(false);
    }
    if(hasPrevResult()){
        emit hasPrevResultChanged(true);
    }else{
        emit hasPrevResultChanged(false);
    }
}
