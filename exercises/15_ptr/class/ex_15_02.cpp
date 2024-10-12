/*
    Выполнить сложение значений переменных с использованием указателей на эти переменные
*/

#include<iostream>
#include<ctime>
using namespace std;

int main()
{
    int c;
    

    cout<<" Введите количество значений "<<endl;
    cin>>c;
    int *a = new int[c];
    srand(time(0));
    for (int i=0;i<c;i++)
    {
        a[i]=rand()%10;
        cout<<a[i]<<endl;
    }
    cout<<*a<<endl;
    cout<<"Размер = "<<sizeof(a)<<endl;
    cout<<"Размер = "<<sizeof(*a)*c<<endl;
    delete a;
    
}