/*
Составить программу, которая содержит динамическуинфрмацию о наличии автобусов в автобусном парке.
Сведения о каждом автобусе содержат:
- номер автобуса;
- фамилию и инициалы водителя;
- номер маршрута;
Программа должна обеспечивать:
- Начальное формирование  данных о всех автобусах в парке в виде списка;
- при выезде каждого автобуса из парка вводится номер автобуса, и программа удаляет данные об этом автобусе из списка автобусов, 
находящихсяв парке, и записывает эти данные в список автобусов, находящихся на маршруте;
- при въезде каждого автобуса в парка вводится номер автобуса, и программа удаляет данные об этом автобусе из списка автобусов, 
находящихся на маршруте, и записывает эти данные в список автобусов, находящихся в парке;
- по запросу выдаются сведения об автобусах, находящихся в парке, или об автобусах, находящихся на маршруте
*/

#include <iostream>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Bus{
    string num;
    string fio;
    string mar;
    int st;     //0 - в парке, 1 - на маршруте, 2 - ремонт
    Bus *p;
};

Bus * first(string num, string fio, string mar)
{
    Bus * bus = new Bus;
    bus->num=num;
    bus->fio=fio;
    bus->mar=mar;
    bus->st=0;
    bus->p=0;
    return bus;
}

void insert_bus(Bus **top,string num, string fio, string mar)
{
    Bus * bus =new Bus;
    bus->num=num;
    bus->fio=fio;
    bus->mar=mar;
    bus->st=0;
    bus->p=*top;
    *top=bus;
}

void print_bus(Bus *const top,int st=-1)
{
    Bus *t=top;
    cout<<st<<endl;
    switch (st){
        case -1: cout<<"В наличии"<<endl;break;
        case 0: cout<<"В парке"<<endl;break;
        case 1: cout<<"На маршруте"<<endl;break;
        case 2: cout<<"В ремонте"<<endl;break;
    }

    while(t)
    {
        if (st==-1)
            cout<<t->num<<" "<<t->fio<<" "<<t->mar<<endl;
        else if (t->st==st)
            cout<<t->num<<" "<<t->fio<<" "<<t->mar<<endl;
        t=t->p;
    }
}

Bus * find_bus(Bus * const  top,string num)
{
    Bus * t=top;
    while (t->num!=num)
        t=t->p;
    return t;
}

void insert_route(Bus **top)
{
    string num;
    cout<<"Введите номер автобуса"<<endl;
    cin>>num;
    Bus *t = find_bus(*top,num);
    t->st=1;
}

int main()
{
    string num;
    string fio;
    string mar;
    ifstream f;
    int vubor=0;
    f.open("bus.txt");
    getline(f,num);
    getline(f,fio);
    getline(f,mar);

    Bus * top=first(num,fio,mar);
    while (!f.eof()){
        getline(f,num);
        getline(f,fio);
        getline(f,mar);
        insert_bus(&top,num,fio,mar);
    }
    cout<<"Печать автобусов"<<endl;
    print_bus(top);
    cout<<endl;
    cout<<"Печать автобусов"<<endl;
    print_bus(top,2);
    cout<<endl;
    f.close();
    while (vubor!=1000)
    {
        cout<<"Выберите дейстие"<<endl;
        cout<<"1 - поставить автобус на маршрут"<<endl;
        cout<<"2 - напечатать список автобусов на маршрутах"<<endl;
        cout<<"3 - напечатать список автобусов в парке"<<endl;
        cout<<"1000 - завершение работы"<<endl;
        cin>>vubor;

        switch (vubor){
            case 1:insert_route(&top);break;
            case 2:print_bus(top,1);break;
            case 3:print_bus(top,0);break;
        }
    }
}