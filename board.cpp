#include "board.h"

int Board::currentNumber() const
{
    return m_currentNumber;
}

void Board::setCurrentNumber(int newCurrentNumber)
{
    m_currentNumber = newCurrentNumber;
}

int Board::cellsCount() const
{
    return m_cellsCount;
}

void Board::setCellsCount(int newCellsCount)
{
    m_cellsCount = newCellsCount;
}

std::pair<int, int> Board::getIndex(int n) const
{
    return std::make_pair(n/m_size, n%m_size);
}

void Board::setAvailableSteps(int i, int x, int y)
{
    m_availableSteps[i][0] = x;
    m_availableSteps[i][1] = y;
}

void Board::setHistoryStep(int i, int x, int y)
{
    history[i][0] = x;
    history[i][1] = y;
}

Board::Board() : Board(defaultSize){}

Board::Board(int n)
{
    m_size = n;
    m_cellsCount = m_size*m_size;
    field = new int*[m_size];
//    history = new int*[m_cellsCount];
    for(int i=0;i<m_size;i++){
        field[i] = new int[m_size]{0};
//        history[i] = new int[2]{0};
    }
}

Board::~Board()
{
    for(int i=0;i<m_size;i++){
        delete field[i];
//        delete history[i];
    }
    delete field;
//    delete history;
}

bool Board::isOnField(std::pair<int, int> point)
{
    if(point.first >= 0 && point.second >= 0){
        if(point.first < m_size && point.second < m_size){
            return true;
        }
    }
    return false;
}

bool Board::isCellFree(std::pair<int, int> point)
{
    if(field[point.first][point.second] != 0){
        return false;
    }
    return true;
}

void Board::getSteps(std::pair<int, int> point)
{
    constexpr int directions[8][2] = {{2,1}, {2, -1}, {1,-2}, {-1, -2}, {-2,-1}, {-2, 1}, {-1,2}, {1, 2}};
    m_availableStepsCount = 0;
    for(auto i : directions){
        std::pair<int, int> checking = {i[0]+point.first, i[1]+point.second};
        if(isOnField(checking) && isCellFree(checking)){
            setAvailableSteps(m_availableStepsCount++, checking.first, checking.second);
        }
    }
}

int Board::size() const
{
    return m_size;
}

void Board::setSize(int newSize)
{
    m_size = newSize;
    m_cellsCount = m_size*m_size;
}

void Board::takeStep(int n)
{
    auto x = getIndex(n);
    if(currentNumber() == 1){
//        setHistoryStep(currentNumber()-1, x.first, x.second);
        field[x.first][x.second] = m_currentNumber++;
        getSteps(x);
        return;
    }else{
        for(int i=0;i<m_availableStepsCount;i++){
            if(x.first == m_availableSteps[i][0] && x.second == m_availableSteps[i][1]){
//                setHistoryStep(currentNumber()-1, x.first, x.second);
                field[x.first][x.second] = m_currentNumber++;
                if(currentNumber() > m_cellsCount){
                    //victory
                }
                getSteps(x);
                return;
            }
        }
    }

}

int Board::getCell(int n) const
{
    auto i = getIndex(n);
    return field[i.first][i.second];
}

