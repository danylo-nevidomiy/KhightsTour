#ifndef HORSE_H
#define HORSE_H

#include <QObject>

class Horse : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int size READ getSize WRITE setSize NOTIFY sizeChanged)
public:
    Horse();
    Horse(int n);
    Horse(int n, std::pair<int, int> point);
    ~Horse();

    void setStart(std::pair<int, int> start);

    int **field;
    int size = 7;
    int cellsCount;
    std::vector<int**> results;
    std::pair<int, int> start = {0,0};

    std::vector<std::pair<int, int>> getSteps(std::pair<int, int> point);
    bool isOnField(std::pair<int, int> point);
    bool isCellFree(std::pair<int, int> point);

    void pathFinder(std::pair<int, int> current, int number);
    void saveResult(int** result);

    void drawField();
    void find();
    void draw();
    void drawPath(int **path);

    int getSize() const;
    void setSize(int size);

signals:
    void sizeChanged();

};

#endif // HORSE_H
