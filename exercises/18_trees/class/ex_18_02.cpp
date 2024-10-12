/**
 * @file ex_18_02.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * Движение поездов чз станцию с помощью бинарного дерева 
 */

#include<iostream>
#include<ctime>
#include<string.h>
//#include<stdio.h>
#include<fstream>
#include <sys/sysinfo.h>

using namespace std;

struct Train{
    string key;
    string name;
    string tim;
    Train * left;
    Train * right;
};

void print_train(Train * p,int level){
    if (p){
        print_train(p->left,level+1);
        for (int i=0;i<=level;i++)
            cout<<"   ";
        cout<<p->key<<endl;
        print_train(p->right,level+1);
    }
}

void delete_tree(Train **p)
{
    if (*p){
        delete_tree(&((*p)->left));
        delete_tree(&((*p)->right));
        delete (*p);
    }
}

Train * first(string key,string name,string tim)    //формирование корня дерева
{
    Train * pnew = new Train;
    pnew->key=key;
    pnew->name=name;
    pnew->tim=tim;
    pnew->left=0;
    pnew->right=0;
    return pnew;
}

Train * search_insert(Train * root,string key,string name,string tim){
    Train *pv=root;
    Train *prev;
    bool found =false;
    while(pv && !found){
        prev=pv;
        if (pv->key==key){
            found=true;
        }
        else if(key<(pv->key)){
                    pv=pv->left;
              }
            else
            {
                pv=pv->right;
            }    
    }
    if (found)
        return pv;

    Train * pnew = new Train;
    pnew->key=key;
    pnew->name=name;
    pnew->tim=tim;
    pnew->left=0;
    pnew->right=0;
    if (key<prev->key)
        prev->left=pnew;        //ставим элемент в левое поддерево
    else   
        prev->right=pnew;       //ставим элемент в правое поддерево
    return pnew;
}

void print_info(Train *root,string key){
        Train * p=search_insert(root,key,"0","0");
        if (p){
            cout<<p->key<<" "<<p->name<<" "<<p->tim<<endl;
        }
    }

void  list_train_to(Train * p,string name){
    if (p){
        list_train_to(p->left,name);
        if (name==p->name)
            cout<<p->key<<" "<<p->name<<" "<<p->tim<<endl;
        list_train_to(p->right,name);
    }

}

int main(){
    string key;
    string name;
    string tim;
    ifstream f;
    int menu=0;
    f.open("train.txt");
    getline(f,key);
    getline(f,name);
    getline(f,tim);
    
    Train * root = first(key,name,tim);
    
    while(!f.eof()){
        getline(f,key);
        getline(f,name);
        getline(f,tim);
        //cout<<key<<" "<<name<<" "<<tim<<endl;
        search_insert(root,key,name,tim);
    }
    f.close();
    print_train(root,1);
     while (menu!=1000){
        cout<<"Выберите операцию (1 - добавить элемент, 0 - просмотр сведений, 2 - напечатать дерево поездов,1000 - выход)"<<endl;
        cin>>menu;
        
        if (menu==0){
            cout<<"Введите поезда"<<endl;
            cin>>key;
            print_info(root,key);
            //delete_elem(root,i);
            print_train(root,1);
        }
        
        if (menu==1){
            cout<<"Номер поезда:"<<endl;
            cin>>key;
            cout<<"Пункт назначения:"<<endl;
            cin>>name;
            cout<<"Время отправления"<<endl;
            cin>>tim;
            search_insert(root,key,name,tim);
           // print_train(root,1);
        }     
        if (menu==2)
        {
            print_train(root,1);
        }
        if (menu==3)
        {
            cout<<"Пункт назначения:"<<endl;
            cin>>name;
            list_train_to(root,name);
        }
    }
    
    //getchar();
    delete_tree(&root);
}