#ifndef TOURFINDER_H
#define TOURFINDER_H

#include <vector>
#include <iostream>

//#include <QPromise>

class TourFinder
{
    int **field;
    int size = 7;
    int cellsCount;
    std::vector<std::vector<int>> results;

    std::vector<std::pair<int, int>> getSteps(std::pair<int, int> point);
    bool isOnField(std::pair<int, int> point);
    bool isCellFree(std::pair<int, int> point);
    void saveResult(int** result);
public:
    TourFinder();
    TourFinder(int n);
    ~TourFinder();
    int getSize() const;
    void setSize(int newSize);
    std::vector<int> getResult(int index) const;
    inline int getResultsCount() const{
        return results.size();
    };
//    void pathFinder(QPromise<std::vector<int>> &promise, std::pair<int, int> current, int number);
    void pathFinder(std::pair<int, int> current, int number);

};

#endif // TOURFINDER_H
