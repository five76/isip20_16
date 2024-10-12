#include<iostream>
#include<fstream> 
#include<ctime>
#include<stdio.h>

using namespace std;
static const int N=10000;
int main(){
    int i,j,id[N],sz[N];
    int p,q;
    int f1,f2;
    for (i=0;i<N;i++){
        id[i] = i;
        sz[i] = 1;
    }
    ifstream f;
    cout<<"Введите последовательно номера объектов для проверки связи между ними"<<endl;
    cin>>f1>>f2;
    f.open("data.txt");
    clock_t tStart;
    tStart = clock(); 
    while (f>>p>>q)
    {
        for (i=p;i!=id[i];i=id[i])
            id[i]=id[id[i]];
        for (j=q;j!=id[j];j=id[j])
            id[j]=id[id[j]];
        if (i==j) continue;
        if (sz[i]<sz[j])
        {
            id[i]=j;
            sz[j]+=sz[i];
        }
        else
        {
            id[j]=i;
            sz[i]+=sz[j];
        }
       // cout<<" "<<p<<" "<<q<<"   -   ";
      //  for (int k=0;k<100;k++) cout<<" "<<id[k];
      //  cout<<endl;
    }
    //printf("Процесс ввода занял: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    f.close();
   // cout<<"Введите последовательно номера объектов для проверки связи между ними"<<endl;
    //cin>>p>>q;
    //tStart = clock(); 
    
    for (i=f1;i!=id[i];i=id[i]);
    for (j=f2;j!=id[j];j=id[j]);
        

    if (i==j)
        cout<<"Объекты связаны"<<endl;
    else   
        cout<<"Объекты не связаны"<<endl;
    
    /*
    if (id[f1]==id[f2])
        cout<<"Объекты связаны"<<endl;
    else   
        cout<<"Объекты не связаны"<<endl;
    */
    printf("Процесс поиска связности занял: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}