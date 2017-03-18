#include "source.h"

source::source():QObject(NULL){}
void source::start(unsigned short disks, unsigned short towerIn, unsigned short towerOut){
    _result.clear();
    hanoi(disks,towerIn,towerOut);
    emit generated();
}
source::~source(){}
unsigned short source::findTower(unsigned short a,unsigned short b){
    for(unsigned short i=0;i<3;i++)
        if(i!=a&&i!=b)return i;
    return 0;
}
void source::hanoi(unsigned short disk,unsigned short a,unsigned short b){
    if(!disk)return;
    unsigned short temp=findTower(a,b);
    hanoi(disk-1,a,temp);
    _result.push_back("STEP "+QString::number(_result.size()+1)+":  move disk "+QString::number(disk)+" from  stack "+QString::number(a)+" to stack "+QString::number(b));
    hanoi(disk-1,temp,b);
}
void source::save(QString patch){
    patch.remove("file://");
    QFile f(patch);
    if(f.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QTextStream stream(&f);
        stream<<"steps="<<QString::number(_result.size())<<"\n";
        for(int i=0;i<_result.size();i++){
            stream<<_result[i]<<"\n";
        }
        f.close();
    }
}
void source::save(){
   // patch.remove("file://");
    QFile f(QFileDialog::getSaveFileUrl(this,"Save Solution dialog"));
    if(f.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        QTextStream stream(&f);
        stream<<"steps="<<QString::number(_result.size())<<"\n";
        for(int i=0;i<_result.size();i++){
            stream<<_result[i]<<"\n";
        }
        f.close();
    }
}
QStringList source::result()const{
    return _result;
}
