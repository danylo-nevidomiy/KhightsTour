#include "toursagregator.h"

//const std::pair<int, int> &ToursAgregator::getStart() const
//{
//    return start;
//}

//void ToursAgregator::setStart(const std::pair<int, int> &newStart)
//{
//    if (start == newStart)
//        return;
//    start = newStart;
//    emit startChanged();
//}

void ToursAgregator::step(int index)
{
    if(board->takeStep(index)){
        emit victory();
    }
    emit dataChanged(createIndex(index, 0), createIndex(index, 0));
}

void ToursAgregator::clear()
{
    delete board;
    board = new Board();
    emit dataChanged(createIndex(0, 0), createIndex(board->cellsCount(), 0));
}

void ToursAgregator::changeBoard(int n)
{
    qDebug() << "ToursAgregator::changeBoard(int n)";
    delete board;
    board = new Board(n);
    emit dataChanged(createIndex(0, 0), createIndex(board->cellsCount(), 0));
}

void ToursAgregator::forward()
{
    int update = board->forward();
    if(update > -1){
        emit dataChanged(createIndex(update, 0), createIndex(update, 0));
    }

}

void ToursAgregator::back()
{
    int update = board->back();
    if(update > -1){
        emit dataChanged(createIndex(update, 0), createIndex(update, 0));
    }
}

int ToursAgregator::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return cellsCount();
}

QVariant ToursAgregator::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return {};
    }
//    qDebug() << "TOUR: index.row() = " << index.row();
    int n = board->getCell(index.row());
    if(n == 0){
        return QVariant(" ");
    }
    return QVariant(n);

}

ToursAgregator::ToursAgregator() : ToursAgregator(5){}

ToursAgregator::ToursAgregator(int n)
{
    board = new Board(n);
}

ToursAgregator::~ToursAgregator()
{
    delete board;
}

int ToursAgregator::getResultsCount() const
{
//    return tour->getResultsCount();
    return 0;
}

int ToursAgregator::getResultsValueAt(const int index) const
{
    return currentResult.at(index);
}

int ToursAgregator::nextResult()
{
//    if(current<tour->getResultsCount()){
//        emit currentChanged(++current+1);
//        currentResult = tour->getResult(current);
//    }
//    updateCurrentStates();
//    return current;
    return 0;
}

int ToursAgregator::prevResult()
{
//    if(current>0){
//        emit currentChanged(--current+1);
//        currentResult = tour->getResult(current);
//    }
//    updateCurrentStates();
//    return current;
    return 0;
}

bool ToursAgregator::hasNextResult() const
{
//    if(current<tour->getResultsCount()){
//        return true;
//    }
//    return false;
    return false;
}

bool ToursAgregator::hasPrevResult() const
{
//    if(current>0){
//        return true;
//    }
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



//    tour->pathFinder(start, 1);
//    emit resultCountChanged(tour->getResultsCount());
//    current = 0;
//    emit currentChanged(current+1);
//    updateCurrentStates();

}

int ToursAgregator::size() const
{
    return board->size();
}

void ToursAgregator::setSize(int newSize)
{
    board->setSize(newSize);
    emit sizeChanged(newSize);
}

int ToursAgregator::cellsCount() const
{
    return board->cellsCount();
}

void ToursAgregator::setCellsCount(int newCellsCount)
{
    board->setCellsCount(newCellsCount);
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
