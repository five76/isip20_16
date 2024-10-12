/*
Лабиринт
*/

#include <iostream>
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip> 
#include<utility>

using namespace std;

struct Path{
    int x;
    int y;
    int s;
    Path * next;
};

void print_arr2(int *a,int m)
{
    for (int i=0;i<m;i++)
    {
        cout<<a[i]<<" ";
    }
}

void print_arr(int *a,int n,int m)
{
    for (int i=0;i<m;i++)
    {
        cout<<setw(2)<<a[i]<<" ";
        //print_arr2(&a[i],m);
    }
}

void print_path()
{
    cout<<"Маршрут";
}

void step(int **a,int n,int m,int i,int j,int v)
{
    
    if (i<0 || i>=n || j<0 || j>=m)
        return ; 
    
    if (a[i][j]==1)
    {
       
        a[i][j]=v+1;
        v=a[i][j];
        step (a,n,m,i-1,j,v);
        step (a,n,m,i,j+1,v);
        step (a,n,m,i+1,j,v);
        step (a,n,m,i,j-1,v);
   } 
}

Path * create_path(int **a,Path **path,int n,int m,int i,int j,int v)
{
    if (i<0 || i>n-1 || j<0 || j>m-1 || a[i][j]==0 || a[i][j]>v)
        return 0;

   // while (v>1){
    
        if (a[i][j]==v-1)      //если значение в ячейке меньше, чем в предыдущей по маршруту
        {
            Path *  p = new Path;
            p->x=i;
            p->y=j;
            p->s= a[i][j];
            p->next=*path;
            *path=p;
        }

            create_path (a,path,n,m,i-1,j,a[i][j]);
            create_path (a,path,n,m,i,j+1,a[i][j]);
            create_path (a,path,n,m,i+1,j,a[i][j]);
            create_path (a,path,n,m,i,j-1,a[i][j]);
        
    //}
    return *path;
    
}

pair <int, pair<int,int>> find_ExitPoint(int **a,int n,int m)
{
    int max=a[0][0];
    int max_i,max_j;
    int i ,j;
    for (i=0;i<n;i++){
        for (j=0;j<m;j++)    
            if (a[i][j]>max && (i==0 || i==n-1 || j==0 || j==m-1)) 
            {
                max=a[i][j];
                max_i=i;
                max_j=j;
            }
    }
    return make_pair(max,make_pair(max_i,max_j));
}   

void print_path(Path * const top)
{
    ofstream f1;
    f1.open("path.txt");
    Path *t=top;
    while (t)
    {
        //cout<<t->x<<" "<<t->y<<endl;
        f1<<t->x<<" "<<t->y<<endl;
        t=t->next;
    }
    f1.close();
    //return temp;
}

int main()
{
    int n;
    int m;
    int x;
    int y;
    pair <int,pair<int,int>> ExitPoint;
    string ns;
    string nm;
    ifstream f;
    f.open("labirint.txt");
    f>>n;
    f>>m;
    //cout<<n<<" "<<m<<endl;

    int ** a = new int* [n];
    for (int i=0;i<n;i++)
    {
        a[i] = new int[m];
    }
    cout<<endl;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            a[i][j] = 0;
    }
    cout<<endl;

    while (!f.eof())
    {
        f>>x;
        f>>y;
        a[x][y]=1;
    }
/*
    for (int i=0;i<n;i++){
        print_arr(a[i],n,m);
        cout<<endl;
    }
*/
    //поиск маршрута
    step(a,n,m,2,0,0);
    ExitPoint=find_ExitPoint(a,n,m);
    cout<<endl;
    
    cout<<"Точка выхода "<<ExitPoint.second.first<<" "<<ExitPoint.second.second<<endl;
    cout<<"Длина маршрута "<<ExitPoint.first<<endl;
    //cout<<"After select path"<<endl;

    /*
    for (int i=0;i<n;i++){
        print_arr(a[i],n,m);
        cout<<endl;
    }
    */
    
    //формирование маршрута
    Path * path = new Path;
    path->x=ExitPoint.second.first;
    path->y=ExitPoint.second.second;
    path->s=ExitPoint.first;
    path->next=0;

    print_path(create_path(a,&path,n,m,path->x,path->y,path->s));


    //удаление динамического массива
    for (int i=0;i<n;i++)
    {
        delete [] a[i];
    }
    
    f.close();
}