#include <iostream>
#include "horse.h"

Horse::Horse(int n, std::pair<int, int> point) : Horse(n)
{
    if(isOnField(point)){
        start = point;
    }
}

Horse::Horse() : Horse(5)
{

}

Horse::Horse(int n)
{
    size = n;
    cellsCount = size*size;
    field = new int*[size];
    for(int i=0;i<size;i++){
        field[i] = new int[size]{0};
    }
}

Horse::~Horse()
{
    for(int i=0;i<size;i++){
       delete field[i];
    }
    delete field;
}

void Horse::drawField()
{
//    drawPath(field);
}

void Horse::find()
{
    pathFinder(start, 1);
//    for(int i=0;i<size;i++){
//        for(int j=0;j<size;j++){
//            pathFinder(std::make_pair(i, j), 1);

//        }
//    }

}

void Horse::draw()
{
    for(auto i : results){
        drawPath(i);
        std::cout << "||||||||||||||||||||||||||||||||||||||||||" <<std::endl;
    }
    std::cout << "Count = " << results.size() <<std::endl;
}

void Horse::drawPath(std::vector<int> path)
{
    std::cout << "||||||||||||||||||||||||||||||||||||||||||" <<std::endl;
    for(int i=0;i<size;i++){
        std::cout << "[ ";
        for(int j=0;j<size;j++){
            std::cout << path.at(index(i, j)) << "\t ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "||||||||||||||||||||||||||||||||||||||||||" <<std::endl;
}

int Horse::getSize() const
{
    return size;
}

void Horse::setSize(int size)
{
    this->size = size;
}

std::vector<int> Horse::getResult(int index) const
{
    return results.at(index);
}

int Horse::appendCurrentResult()
{
    if(currentResult<results.size()){
        return ++currentResult;
    }
}

int Horse::deductCurrentResult()
{
    if(currentResult>0){
        return --currentResult;
    }
}

void Horse::setStart(std::pair<int, int> start)
{
    this->start = start;
}

bool Horse::isOnField(std::pair<int, int> point)
{
    if(point.first >= 0 && point.second >= 0){
        if(point.first < size && point.second < size){
            return true;
        }
    }
    return false;
}

void Horse::pathFinder(std::pair<int, int> current, int number)
{
    if(number == cellsCount){
        field[current.first][current.second] = number;
        saveResult(field);
        field[current.first][current.second] = 0;
//        drawPath(field);
        std::cout << "Count = " << results.size() <<std::endl;
        return;
    }


//    std::cout << "||||||||||||||||||||||" << std::endl;
    auto steps = getSteps(current);
    if(steps.size() == 0){
        return;
    }
//    std::cout << "number = " << number << std::endl;
//    std::cout << "steps = " << steps.size() << std::endl;
//        for(auto i : steps){
//        std::cout << "["<< i.first <<", "<< i.second << "]" << std::endl;
//        }
    field[current.first][current.second] = number;
//    drawField();
    for(auto i : steps){
        pathFinder({i.first, i.second}, number+1);
    }
    field[current.first][current.second] = 0;
}

std::vector<std::pair<int, int> > Horse::getSteps(std::pair<int, int> point)
{
    std::vector<std::pair<int, int>> steps;
    constexpr int directions[8][2] = {{2,1}, {2, -1}, {1,-2}, {-1, -2}, {-2,-1}, {-2, 1}, {-1,2}, {1, 2}};
    for(auto i : directions){
        std::pair<int, int> checking = {i[0]+point.first, i[1]+point.second};
        if(isOnField(checking) && isCellFree(checking)){
            steps.push_back(checking);
        }
    }
    return steps;
}

void Horse::saveResult(int** result)
{
    std::vector<int> answer;
    int** array = new int*[size];
    for(int i=0;i<size;i++){
        array[i] = new int[size]{0};
        for(int j=0;j<size;j++){
            answer.push_back(result[i][j]);
        }
    }
    results.push_back(answer);
}

bool Horse::isCellFree(std::pair<int, int> point)
{
    if(field[point.first][point.second] != 0){
        return false;
    }
    return true;
}
