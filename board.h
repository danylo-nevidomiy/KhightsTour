#ifndef TOUR_H
#define TOUR_H

#include <QObject>

static constexpr int defaultSize = 5;

class Board
{
    int **field;
    int m_size;
    int m_cellsCount;
    int m_currentNumber = 1;
    int m_availableSteps[8][2];
    int m_availableStepsCount = 0;
    std::pair<int, int> getIndex(int n) const;
    int **history;
    std::pair<int, int> current;
    void setAvailableSteps(int i, int x, int y);
    void setHistoryStep(int i, int x, int y);
public:
    Board();
    Board(int n);
    virtual ~Board();
    bool isOnField(std::pair<int, int> point);
    bool isCellFree(std::pair<int, int> point);
    void getSteps(std::pair<int, int> point);

    int size() const;
    void setSize(int newSize);
    void takeStep(int n);
    int getCell(int n) const;
    int currentNumber() const;
    void setCurrentNumber(int newCurrentNumber);
    int cellsCount() const;
    void setCellsCount(int newCellsCount);
};

#endif // TOUR_H
