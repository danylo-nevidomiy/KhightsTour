#include "tourfinder.h"

int TourFinder::getSize() const
{
    return size;
}

void TourFinder::setSize(int newSize)
{
    size = newSize;
    cellsCount = size*size;
}

std::vector<int> TourFinder::getResult(int index) const
{
    return results.at(index);
}

//void TourFinder::pathFinder(QPromise<std::vector<int>> &promise, std::pair<int, int> current, int number)
//void TourFinder::pathFinder(ResultHandler handler, std::pair<int, int> current, int number)

//void TourFinder::pathFinder(std::pair<int, int> current, int number){
//    if(number == cellsCount){
//        field[current.first][current.second] = number;
//        saveResult(field);
////        handler(saveResult(field));
//        field[current.first][current.second] = 0;
//        std::cout << "Count = " << results.size() <<std::endl;
//        return;
//    }
//    auto steps = getSteps(current);
//    if(steps.size() == 0){
//        return;
//    }
//    field[current.first][current.second] = number;
//    for(auto i : steps){
//        pathFinder({i.first, i.second}, number+1);
//    }
//    field[current.first][current.second] = 0;
//}
void TourFinder::pathFinder(std::pair<int, int> current, int number)
{
    if(number == cellsCount){
        field[current.first][current.second] = number;
        saveResult(field);
        field[current.first][current.second] = 0;
        std::cout << "Count = " << results.size() <<std::endl;
        return;
    }
    auto steps = getSteps(current);
    if(steps.size() == 0){
        return;
    }
    field[current.first][current.second] = number;
    for(auto i : steps){
        pathFinder({i.first, i.second}, number+1);
    }
    field[current.first][current.second] = 0;
}

std::vector<std::pair<int, int>> TourFinder::getSteps(std::pair<int, int> point)
{
    availableSteps.clear();
    constexpr int directions[8][2] = {{2,1}, {2, -1}, {1,-2}, {-1, -2}, {-2,-1}, {-2, 1}, {-1,2}, {1, 2}};
    for(auto i : directions){
        std::pair<int, int> checking = {i[0]+point.first, i[1]+point.second};
        if(isOnField(checking) && isCellFree(checking)){
            availableSteps.push_back(checking);
        }
    }
    return availableSteps;
}

void TourFinder::takeStep(std::pair<int, int> step)
{
    for(auto i : availableSteps){
        if(step == i){
            field[step.first][step.second] = currentNumber++;
        }
    }
}

bool TourFinder::isOnField(std::pair<int, int> point)
{
    if(point.first >= 0 && point.second >= 0){
        if(point.first < size && point.second < size){
            return true;
        }
    }
    return false;
}

bool TourFinder::isCellFree(std::pair<int, int> point)
{
    if(field[point.first][point.second] != 0){
        return false;
    }
    return true;
}

void TourFinder::saveResult(int** result)
{
    std::vector<int> answer;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            answer.push_back(result[i][j]);
        }
    }
    results.push_back(answer);
}

void TourFinder::saveResultNow(std::vector<int> res)
{
    results.push_back(res);
//    emit resultCountChanged(results.size());
}

TourFinder::TourFinder() : TourFinder(5){}

TourFinder::TourFinder(int n)
{
    size = n;
    cellsCount = size*size;
    field = new int*[size];
    for(int i=0;i<size;i++){
        field[i] = new int[size]{0};
    }
}

TourFinder::~TourFinder()
{
    for(int i=0;i<size;i++){
        delete field[i];
    }
    delete field;
}
