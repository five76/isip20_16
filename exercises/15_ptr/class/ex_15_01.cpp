/*
    Выполнить сложение значений переменных с использованием указателей на эти переменные
*/

#include<iostream>
#include<ctime>
using namespace std;

int main()
{
    int a=2;
    int b=3;
    int *pta;
    int *ptb;
    int *ptsum;
    int M[]={2,3,6,-1,45,20,10,-3};
    int *ptk;

    pta=&a;     //в pta "положить" АДРЕС переменной a

    cout<<"Адрес переменной a "<<pta<<endl;
    cout<<"Значение переменной a = "<<a<<endl;
    cout<<"Значение переменной a (через разъыменование *pta) = "<<*pta<<endl;


    ptb=&b;     //в ptb "положить" АДРЕС переменной b
    cout<<"Адрес переменной b "<<ptb<<endl;
    cout<<"Значение переменной b "<<b<<endl;
    cout<<"Значение переменной b (через разъыменование *ptb) = "<<*ptb<<endl;
    
    //*pta - обратиться по адресу, хранимому в pta и взять оттуда значение

    *ptsum = *pta + *ptb;

    cout<<"ptsum = "<<ptsum<<endl;
    cout<<"Значение, находящееся в памяти по адресу "<<ptsum<<" = "<<*ptsum<<endl;
    cout<<"Размер = "<<sizeof(ptsum)<<endl;
    cout<<"Размер = "<<sizeof(*ptsum)<<endl;

    //ptk=M;
    //cout<<"Размер = "<<sizeof(ptk)<<endl;
    //cout<<"Размер = "<<sizeof(M)<<endl;

}