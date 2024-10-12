/*
    Описать класс точка.
    Поля: координаты точки;
    Методы: вычисление расстояния от точки до начала координат.
*/
#include <iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

class Point{
    private:
        double r;
    public:
        int x;
        int y;
        Point (int _x,int _y)
        {
            x=_x;
            y=_y;
        }
        double GetRadius(){
            r = sqrt(pow(x,2.0)+(y,2.0));
            return r;
        }

};

int main(){
    
    Point A(1,1);
    cout<<A.GetRadius()<<endl;

}