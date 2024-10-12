/*
    Для целочисленной квадратной матрицы найти число элементов, кратных k.
    Требования к программе: 
    Генерацию матрицы, вывод матрицы и поиск элементов выполнять в разных функциях
    Спецификация функций:
    pair<int,int> find_count_max(int A[n][m], int k)
    Вход - массив NxM, число k (для поиска кратных значений)
    Выход - ПАРА ЭЛЕМЕНТОВ: число элементов, кратных k и максимальное из этих чисел
    
    pair 
        Структура, позволяющая обрабатывать два объекта как один объект.
            Синтаксис:
        pair<type_el1,type_el2> obj =(val1,val2)
            Например:
        pair <int, double> p1 ( 10, 1.1e-2 );
        pair <int, double> p2;
        p2 = make_pair ( 10, 2.22e-1 );
        cout.precision ( 3 );
        cout << "The pair p1 is: ( " << p1.first << ", " << p1.second << " )." << endl;
        cout << "The pair p2 is: ( " << p2.first << ", " << p2.second << " )." << endl;
*/
#include<iostream>
#include<ctime>
#include<stdio.h>
using namespace std;

const int n = 3;
const int m = 4;

void gen_matrix(int A[n][m])
{
    int i,j;
    srand(time(0));
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            A[i][j] = -10 + rand()%20;
        }
    }
}

void print_matrix(int A[n][m])
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            //cout<<A[i][j]<<" "; 
            printf("%5d",A[i][j]);
        }
        cout<<endl;
    }
}

pair<int,int> find_count_max(int A[n][m], int k)
{
    int count=0;
    int max=A[0][0];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
           if (A[i][j]%k==0)    //если элемент массива делится нацело на k, то...
           {
                count++;        //увеличиваем счетчик найденных элементов
                if (A[i][j]>max)
                {
                    max=A[i][j];
                }
           }
        }
    }
    return make_pair(count,max);    //формирование пары элементов
}

int main()
{
    int A[n][m];
    int k=3;
    gen_matrix(A);   
    print_matrix(A);
    cout<<endl;
    cout<<"Элементов, кратных "<<k<<" = "<<find_count_max(A, k).first<<endl;    //вывод первого значения пары
    cout<<"Максимальный из них = "<<find_count_max(A, k).second<<endl;          //вывод второго значения пары
    return 0;
}