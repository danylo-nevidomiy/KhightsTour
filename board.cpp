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

int Board::back()
{
    if(m_historyLength == 1){
        m_historyLength--;
        field[history[m_historyLength][0]][history[m_historyLength][1]] = 0;
        m_currentNumber--;
        return getIndexFromXY(history[m_historyLength][0], history[m_historyLength][1]);
    } else if(m_historyLength>1){
        m_historyLength--;
        field[history[m_historyLength][0]][history[m_historyLength][1]] = 0;
        getSteps(std::make_pair(history[m_historyLength-1][0], history[m_historyLength-1][1]));
        m_currentNumber--;
        return getIndexFromXY(history[m_historyLength][0], history[m_historyLength][1]);
    }
    return noCellsChanged;
}

int Board::forward()
{

    if(m_maxHistoryLength > m_historyLength){
        field[history[m_historyLength][0]][history[m_historyLength][1]] = m_currentNumber++;
        getSteps(std::make_pair(history[m_historyLength][0], history[m_historyLength][1]));
        m_historyLength++;
        return getIndexFromXY(history[m_historyLength-1][0], history[m_historyLength-1][1]);
    }
    return noCellsChanged;
}

std::pair<int, int> Board::getXYFromIdex(int n) const
{
    return std::make_pair(n/m_size, n%m_size);
}

int Board::getIndexFromXY(int x, int y) const
{
    return x*m_size+y;
}

void Board::setAvailableSteps(int i, int x, int y)
{
    m_availableSteps[i][0] = x;
    m_availableSteps[i][1] = y;
}

void Board::setHistoryStep(int x, int y)
{
    if(m_maxHistoryLength > m_historyLength){
        if(history[m_historyLength][0] == x && history[m_historyLength][1] == y){
            m_historyLength++;
            return;
        }else{
            m_maxHistoryLength = m_historyLength + 1;
        }
    }else{
        m_maxHistoryLength++;
    }
    history[m_historyLength][0] = x;
    history[m_historyLength][1] = y;
    m_historyLength++;

}

Board::Board() : Board(defaultSize){}

Board::Board(int n)
    : m_size(n),
    m_cellsCount(m_size*m_size),
    m_currentNumber(defaultCurrentNumber),
    m_availableStepsCount(defaultAvailableStepsCount),
    m_historyLength(defaultHistoryLength),
    m_maxHistoryLength(defaultMaxHistoryLength)
{
    field = new int*[m_size];
    history = new int*[m_cellsCount];
    for(int i=0;i<m_size;i++){
        field[i] = new int[m_size]{0};
    }
    for(int i=0;i<m_cellsCount;i++){
        history[i] = new int[2]{0};
    }
}

Board::~Board()
{
    for(int i=0;i<m_size;i++){
        delete[] field[i];
        delete[] history[i];
    }
    delete[] field;
    delete[] history;
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

bool Board::takeStep(int n)
{
    auto x = getXYFromIdex(n);
    if(currentNumber() == 1){
        setHistoryStep(x.first, x.second);
        field[x.first][x.second] = m_currentNumber++;
        getSteps(x);
        return false;
    }else{
        for(int i=0;i<m_availableStepsCount;i++){
            if(x.first == m_availableSteps[i][0] && x.second == m_availableSteps[i][1]){
                setHistoryStep(x.first, x.second);
                field[x.first][x.second] = m_currentNumber++;
                if(currentNumber() > m_cellsCount){
                    return true;
                }
                getSteps(x);
                return false;
            }
        }
    }
    return false;
}

int Board::getCell(int n) const
{
    auto i = getXYFromIdex(n);
    return field[i.first][i.second];
}

