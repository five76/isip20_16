#include<iostream>
using namespace std;

void print_arr(double *ptM, int len)
{
    int i;
    for (i=0;i<len;i++)
    {
        cout<<ptM[i]<<" ";
    }
}

void change_arr(double *ptM, int len)
{
    int i;
    for (i=0;i<len;i++)
    {
        ptM[i]=2*ptM[i];
    }
}

int main()
{
    double a=5.0;
    double b=7.5;
    double c;
    double M[]={1.5,2.3,-7.4,9.0,5.6};

    double *pta;
    double *ptb;
    double *ptc;
    double *ptM; 
/*
    pta=&a;
    ptb=&b;
    *ptc = *pta+*ptb;
    cout<<*ptc<<endl;
    cout<<ptc<<endl;
    cout<<&c<<endl;
*/
    ptM=M;  //M - имя массива. Является адресом первого элемента (с индексом 0)
    cout<<ptM<<endl;//вывод адреса массива
    cout<<sizeof(ptM)<<endl;    //вывод размера указателя на массив
    cout<<*ptM<<endl;           //вывод первого элемента массива
    cout<<sizeof(*ptM)<<endl;   //размер первого элемента массива
    cout<<sizeof(M)<<endl;

    print_arr(M,sizeof(M)/sizeof(M[0]));

    change_arr(M,sizeof(M)/sizeof(M[0]));
    cout<<endl;
    
    print_arr(M,sizeof(M)/sizeof(M[0]));





}