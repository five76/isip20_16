/*
    Нахождение факториала числа
*/
#include<iostream>
using namespace std;

// Функция вычисления факториала
int factor(int N)
{
    int F=1; //факториал
    for (int i=1;i<=N;i++)
    {
        F=F*i;
    }

    return F;
}

//основная программа
int main()
{
    int N;
    cout<<"Введите число для нахождения факториала"<<endl;
    cin>>N;
    cout<<"Факториал числа "<<N<<" = "<<factor(N)<<endl;
    cout<<N<<"!= "<<factor(N)<<endl;
    return 0;
}

