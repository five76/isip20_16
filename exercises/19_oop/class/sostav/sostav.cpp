#include "sostav.h"
using namespace std;
Sostav::Sostav(int _number,short int _typ){
    p = new Vagon;
    p->number = _number;
    p->typ = _typ;
    p->next=0;
    c=1;
}

Sostav::~Sostav(){
    while (p){
        Vagon *temp = p;
        p = p->next;
        delete temp;
    }
}

Vagon * Sostav::push_sostav(Vagon ** top,int _number,short int _typ)
{
    Vagon *pv = new Vagon;
    pv->number = _number;
    pv->typ = _typ;
    pv->next=*top;
    *top=pv;
    //this->c++;
    return *top;
}  

void Sostav::print_sostav(Vagon **top) const 
{
    Vagon *p = *top;
    while (p){
        cout<<p->number<<" ";
        p=p->next;
    }
}
/*
int Sostav::get_count() 
{
    return count;
}
*/