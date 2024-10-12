/*
Создать двунаправленный список
*/

#include<iostream>
#include<ctime>
using namespace std;

struct Node {
    int d;
    Node *prev;
    Node *next;
};

Node * first(int d)
{
    Node *pv=new Node;
    pv->d=d;
    pv->next=0;
    pv->prev=0;
    return pv;
}

Node * find_elem(Node * const top,int d)
{
    Node *t=top;
    while (t)
    {
        if (t->d==d)
            return t;
        //cout<<t->d<<" ";
        t=t->next;
    }
    return t;
}

void push(Node **pend,int d)
{
    Node *pv=new Node;
    pv->d=d;
    pv->next=0;
    (*pv).prev=*pend;
    (*pend)->next=pv;
    *pend=pv;
}

void insert_elem(Node **pbeg, int d,int val)
{
    Node *pv=find_elem(*pbeg,d);
    Node *ins= new Node;
    ins->d=val;
    ins->prev=pv->prev;
    pv->prev->next=ins;
    ins->next=pv;
}

void print_stek2(Node * const top)
{
    Node *t=top;
    while (t)
    {
        cout<<t->d<<" ";
        t=t->next;
    }
    //return temp;
}


void remove_elem(Node **pbeg, Node **pend,int d)
{
    Node *pv=find_elem(*pbeg,d);
    
    if (pv==*pend)
    {
        //cout<<"Это последний элемент"<<endl;
        (*pend)->prev->next=0;
        *pend=pv->prev;
    }
    else if (pv==*pbeg)
    {
        (*pbeg)->next->prev=0;
        *pbeg=pv->next; 
    }
    else {
       
        pv->prev->next=pv->next;
        pv->next->prev=pv->prev;
    }
    delete pv;
}

int main()
{
    Node *p=first(-100);
    Node *pbeg=p;
    Node *pend=p;
    for (int i=1;i<10;i++)
    {
        push(&pend,i);
    }
    print_stek2(pbeg);
    cout<<endl;
    remove_elem(&pbeg,&pend,9);
    print_stek2(pbeg);
    cout<<endl;
    remove_elem(&pbeg,&pend,2);
    print_stek2(pbeg);
    cout<<endl;
    remove_elem(&pbeg,&pend,-100);
    print_stek2(pbeg);
    cout<<endl;
    insert_elem(&pbeg, 4,34);
    print_stek2(pbeg);
    cout<<endl;
    remove_elem(&pbeg,&pend,34);
    print_stek2(pbeg);
    cout<<endl;
    return 0;
}