#ifndef HORSE_H
#define HORSE_H

#include <QObject>

//Q_DECLARE_METATYPE(std::vector<int>)
//Q_DECLARE_METATYPE(int)

class Horse : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int size READ getSize WRITE setSize NOTIFY sizeChanged)
    Q_PROPERTY(int currentResult READ getCurrentResult WRITE setCurrentResult NOTIFY currentResultChanged)

    inline int index(int i, int j){
        return i*size+j;
    }
public:
    Horse();
    Horse(int n);
    Horse(int n, std::pair<int, int> point);
    ~Horse();

    Q_INVOKABLE void setStart(std::pair<int, int> start);

    int **field;
    int size = 7;
    int cellsCount;
    int currentResult = 0;
    std::vector<std::vector<int>> results;
    std::pair<int, int> start = {0,0};

    std::vector<std::pair<int, int>> getSteps(std::pair<int, int> point);
    bool isOnField(std::pair<int, int> point);
    bool isCellFree(std::pair<int, int> point);

    Q_INVOKABLE void pathFinder(std::pair<int, int> current, int number);
    void saveResult(int** result);

    void drawField();
    Q_INVOKABLE void find();
    void draw();
    void drawPath(std::vector<int> path);

    Q_INVOKABLE int getSize() const;
    Q_INVOKABLE void setSize(int size);
    Q_INVOKABLE std::vector<int> getResult(int index) const;
    inline Q_INVOKABLE int getResultsCount() const{
        return results.size();
    };
    inline Q_INVOKABLE int getResultsValueAt(const int result, const int index) const{
      return results.at(result).at(index);
    };
    Q_INVOKABLE inline int getCurrentResult() const{
        return currentResult;
    };
    Q_INVOKABLE inline void setCurrentResult(int res){
        currentResult = res;
    };
    Q_INVOKABLE int appendCurrentResult();
    Q_INVOKABLE int deductCurrentResult();

signals:
    void sizeChanged();
    void drawBoard(std::vector<int>);
    void currentResultChanged();

};

#endif // HORSE_H
