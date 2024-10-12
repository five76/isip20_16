/*
Создать программу, с исмпльзованием шаблона функции, 
предназначенной для сравнения между собой двух аргументов и возвращающей максимальное значение
*/


#include <iostream>
#include<ctime>
using namespace std;

template <class Type>
Type _max(Type a,Type b){
    if (a>=b)
        return a;
    return b;
}


int main()
{
    cout<<_max(2,3)<<endl;
    cout<<_max('a','b')<<endl;
    return 0;
}