#ifndef TOUR_H
#define TOUR_H

#include <QObject>
#include <iostream>



class Board
{
    static constexpr int defaultSize = 5;
    static constexpr int defaultHistoryLength = 0;
    static constexpr int defaultMaxHistoryLength = 0;
    static constexpr int defaultCurrentNumber = 1;
    static constexpr int defaultAvailableStepsCount = 0;

    static constexpr int noCellsChanged = -1;

    int **field;
    int m_size;
    int m_cellsCount;
    int m_currentNumber;
    int m_availableSteps[8][2];
    int m_availableStepsCount;
    std::pair<int, int> getXYFromIdex(int n) const;
    int getIndexFromXY(int x, int y) const;
    int **history;
    int m_historyLength;
    int m_maxHistoryLength;
    void setAvailableSteps(int i, int x, int y);
    void setHistoryStep(int x, int y);
public:
    Board();
    Board(int n);
    virtual ~Board();
    bool isOnField(std::pair<int, int> point);
    bool isCellFree(std::pair<int, int> point);
    void getSteps(std::pair<int, int> point);

    int size() const;
    void setSize(int newSize);
    bool takeStep(int n);
    int getCell(int n) const;
    int currentNumber() const;
    void setCurrentNumber(int newCurrentNumber);
    int cellsCount() const;
    void setCellsCount(int newCellsCount);
    int back();
    int forward();

};

#endif // TOUR_H
