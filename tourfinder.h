#ifndef TOURFINDER_H
#define TOURFINDER_H

#include <QObject>
#include <vector>
#include <iostream>
#include <queuedispatcher.h>

//#include <QPromise>

class TourFinder
//        : public QObject
{
//    Q_OBJECT
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
    void saveResultNow(std::vector<int> res);
//    void pathFinder(QPromise<std::vector<int>> &promise, std::pair<int, int> current, int number);
//    void pathFinder(ResultHandler handler, std::pair<int, int> current, int number);
    void pathFinder(std::pair<int, int> current, int number);

//signals:
//    void resultCountChanged(int);
};

#endif // TOURFINDER_H
