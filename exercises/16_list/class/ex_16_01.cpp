/*
    Создать стек
*/
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

struct stek{
    int d;
    stek *p;
};

stek * first(int d)
{
    stek * top = new stek;
    top->d=d;
    top->p=0;
    return top;  
}

void push_stek(stek **top,int d)
{
    //cout<<top<<" "<<*top<<" "<<(*top)->p<<endl;
    stek *pv = new stek;
    pv->d=d;
    pv->p=*top;
    *top=pv;
}

int pop(stek **top)
{
    int temp=(*top)->d;
    stek *pp = *top;
    *top=(*top)->p;
    delete pp;
    return temp;
}

int print_stek(stek **top)
{
    int temp=(*top)->d;
    *top=(*top)->p;
    return temp;
}

void print_stek2(stek * const top)
{
    stek *t=top;
    while (t)
    {
        cout<<t->d<<" ";
        t=t->p;
    }
    //return temp;
}

int main()
{
    stek * top= first(-100);
    //cout<<top<<" "<<top->d<<" "<<top->p<<endl;
    for (int i=1;i<10;i++)
        push_stek(&top,i);
    stek *tt=top;   //запоминаем, на что указывает вершина стека
    //cout<<tt<<" "<<top<<endl;
    //cout<<tt->p<<" "<<top->p<<endl;
    //print stack
    /*
    while (top)
        cout<<print_stek(&top)<<endl;
    cout<<"after print"<<endl;
    */
    print_stek2(top);
    cout<<"\nafter print"<<endl;
    //pop stack
    top=tt;         //возвращаем вершину стека обратно
    while (top)
        cout<<pop(&top)<<endl;
    return 0;
}