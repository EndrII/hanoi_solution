#ifndef SOURCE_H
#define SOURCE_H
#include <QObject>
#include <QList>
#include <QFile>
#include <QTextStream>
class source:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList result READ result NOTIFY generated)
private:
    QStringList _result;
    unsigned short findTower(unsigned short a,unsigned short b);
    void hanoi(unsigned short disk,unsigned short a,unsigned short b);
public:
    explicit source();

    ~source();
public slots:
    void start(unsigned short disks, unsigned short towerIn=0, unsigned short towerOut=1);
    void save(QString patch="./result");
    QStringList result()const;
signals:
     void generated();
};

#endif // SOURCE_H
