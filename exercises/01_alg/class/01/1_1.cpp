#include<iostream>
#include<fstream>
#include<stdio.h>
#include<ctime>

using namespace std;
static const int N=10000000;
int main(){
    int i,j,p,q,id[N];
    int f1,f2;
    for (i=0;i<N;i++)
        id[i] = i;
    //for (j=0;j<50;j++) 
      //  cout<<id[j]<<" ";
    cout<<endl;
    ifstream f;
    f.open("data.txt");
    cout<<"Введите последовательно номера объектов для проверки связи между ними"<<endl;
    cin>>f1>>f2;
    clock_t tStart;
    tStart = clock(); 
    while (f>>p>>q)
    {
        int t=id[p];
        if(t==id[q]) continue;
        //if (t==65)
        //    {cout<<" "<<endl;}
        for (i=0;i<N;i++)
            if (id[i] == t) 
                id[i] = id[q];
        //cout<<" "<<p<<" "<<q<<"   -   ";
        //for (int j=0;j<10;j++) cout<<" "<<id[j];
        //cout<<endl;
    }
     //printf("Процесс занял: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    //for (i=0;i<N;i++)
    f.close();
    //for (j=0;j<1000;j++) cout<<id[j]<<" ";
    //cout<<endl;

    //cout<<"Введите последовательно номера объектов для проверки связи между ними"<<endl;
    //cin>>i>>j;
    
    //tStart = clock(); 
    if (id[f1]==id[f2])
        cout<<"Объекты связаны"<<endl;
    else   
        cout<<"Объекты не связаны"<<endl;
    printf("Процесс поиска связности: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}