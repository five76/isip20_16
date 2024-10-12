/*
Сформировать бинарное дерево поиска на основе данных из  файла data.txt


http://www.net-snmp.org/wiki/index.php/Memory_HAL
MEMAVAILREAL:
    MEM_PHYSMEM -> free
        freeBSD: sysctl(VM_METER).t_free
        linux:   /proc/meminfo:MemFree
        win:     GlobalMemoryStatus().dwAvailPhys
*/

#include<iostream>
#include<ctime>
#include<stdio.h>
#include<fstream>
#include <sys/sysinfo.h>

using namespace std;

struct Btree{
    int d;
    Btree * left;
    Btree * right;
};

string memfree()
{
    ifstream f;
    string s;
    int pos;
    f.open("/proc/meminfo");
    while (!f.eof())
    {
        getline(f,s);
        pos=s.find("MemFree:");
        if (pos==0){
            f.close();
            return s;
        }
    }
    f.close();
    return s;
}

Btree * first(int d)    //формирование корня дерева
{
    Btree * pv = new Btree;
    pv->d = d;
    pv->left = 0;
    pv->right = 0;
    return pv;
}

pair <Btree *,Btree *> find_deep(Btree * p)
{
    Btree * pvl=p;
    Btree * pvr=p;
    while(pvl->left){
        pvl=pvl->left;
    }
    while(pvr->right){
        pvr=pvr->right;
    }
    return make_pair (pvl,pvr);

}

pair <Btree *,Btree *> find_for_delete(Btree * root, int d)
{
    Btree * pv = root;
    Btree *prev;
    bool found = false;
    while (pv && !found){
        //prev = pv;            //копируем указатель на узел. 
                                //Впоследствии он будет использоваться в качестве родительского 
        if (d==pv->d)           //если значение найдено, то
            found = true;       //флаг устанавливаем в истину
        else if (d<pv->d){       //иначе, есл d меньше значения текущего ключа, 
                    prev=pv;
                    pv=pv->left;    //то идем влево
                }
             else
                {
                    prev=pv;
                    pv = pv->right;  //иначе идем вправо
                }
    }
    if (found)                  //если элемент найден
        return make_pair(prev,pv);  
}

Btree * search_insert(Btree * root, int d){
    Btree * pv = root;
    Btree *prev;
    bool found = false;
    while (pv && !found){
        prev = pv;              //копируем указатель на узел. 
                                //Впоследствии он будет использоваться в качестве родительского 
        if (d==pv->d)           //если значение найдено, то
            found = true;       //флаг устанавливаем в истину
        else if (d<pv->d){       //иначе, есл d меньше значения текущего ключа, 
                    //prev=pv;
                    pv=pv->left;    //то идем влево
                }
             else
                {
                    //prev=pv;
                    pv = pv->right;  //иначе идем вправо
                }
    }
    if (found)                  //если элемент найден
        return pv;              //то возвращаем его
    //Добавление нового элемента в дерево
    //так как на последнем шаге цикла pv указывает на 0,
    //то использовать в качестве родительского элемента будем prev
    Btree * pnew = new  Btree;
    pnew->d = d;
    pnew->left=0;
    pnew->right=0;
    if (d<prev->d)
        prev->left=pnew;        //ставим элемент в левое поддерево
    else   
        prev->right=pnew;       //ставим элемент в правое поддерево
    return pnew;
}

void delete_elem(Btree * root,int d)
{
    pair <Btree *,Btree *> pr = find_for_delete(root,d);    //находим удаляемый элемент и его предка
    Btree *p;                           //
    Btree *prev;
    Btree *pvl;
    Btree *pvr;
    prev=pr.first;          //предок
    p=pr.second;            //удаляемый элемент

    //Btree * p = search_insert(root,d);
    
    if (p->left==0 && p->right==0) {    //если левое и правое поддеревья удаляемого узла отсутствуют
        Btree *temp = new Btree;
        temp=p;
      
            if (prev->left!=0 && prev->left->d==d)
                prev->left=0;                   //указатель предка ставим в 0    
            else       
                prev->right=0;
       
        delete temp;                    //удаляем элемент
        return;
    }
    
    if (p->left!=0 && p->right==0) {     //если левое поддерево удаляемого узла существует, а правого нет
        Btree *temp = new Btree;
        temp=p;
        if (prev->left->d==d)
           prev->left=p->left;                   //указатель предка ставим в 0
        else
            prev->right=p->left; ;
        delete temp;
        return;
    }

    if (p->left==0 && p->right!=0) {     //если левого поддерева удаляемого узла нет, а правое есть
        Btree *temp = new Btree;
        temp=p;
            if (prev->left!=0 && prev->left->d==d)
                prev->left=p->right;                   //указатель предка ставим в 0
            else
                prev->right=p->right; ;
        
        delete temp;
        return;
    }

    //если левое и правое поддеревья существуют
    if (p->left!=0 && p->right!=0) {
        Btree *temp = new Btree;
        temp=p;
        
        //если в первом элементе правого поддерева имеется левое поддерево,
        //то поднимаем его вверх и ставим вместо удаляемого элемента 
        if (p->right->left!=0){
            //находим самые глубокие элементы этого поддерева, указывающие на 0
            pair <Btree *,Btree *> pr1 = find_deep(p->right->left); 
            pvl=pr1.first;
            pvr=pr1.second;
            if (prev->left->d==d){
                prev->left=p->right->left;
            }    
            else{
                prev->right=p->right->left; 
            }
            pvl->left=p->left;
            pvr->right=p->right;
            p->right->left=0;
            delete temp;
            return;
        }

        if (p->right->left==0){
            p->right->left=p->left;
            if (prev->left->d==d){
                prev->left=p->right;
            }    
            else{
                prev->right=p->right; 
            }

            delete temp;
            return;
        }
    }

}


void print_tree(Btree * p,int level)
{
    if (p){
        
        print_tree(p->right,level+1);
        for(int i=0;i<level;i++)
            cout<<"   ";
        cout<<p->d<<endl;
        print_tree(p->left,level+1); 
    }
}

//удаление дерева
void deleteTree(Btree **root) {
    if (*root) {
        deleteTree(&((*root)->left));
        deleteTree(&((*root)->right));
        delete(*root);
    }
}

int main()
{
    int i,j,d;
    clock_t tStart;
    ifstream f;
    cout<<memfree()<<endl;
    //struct sysinfo info;
    //sysinfo(&info); 
    //printf("Секунд с момента начальной загрузки: %lu (%lu минут)\n", info.uptime, info.uptime/60);
    //printf("Общее количество оперативной памяти: %lu (%lu MB)\n", info.totalram, info.totalram/(1024*1024));
    //printf("Объём доступной памяти: %lu (%lu MB)\n", info.freeram, info.freeram/(1024*1024));

    tStart = clock(); 
    f.open("data.txt");
    f>>d;
    Btree * root = first(d);
    while (!f.eof()){
        f>>d;
        search_insert(root,d);
    }
    //printf("Сортировка заняла: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    f.close();
    print_tree(root,1);
    //  printf("Сортировка заняла: %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    //struct sysinfo info1;
    //sysinfo(&info1);

    //printf("Объём доступной памяти: %lu (%lu MB)\n", info1.freeram, info1.freeram/(1024*1024));    
    getchar();
    cout<<memfree()<<endl;
    i=0;
    cout<<endl;
    cout<<sizeof(root)<<endl;
    while (i!=1000){
        cout<<"Выберите операцию (0 - удалить элемент, 1 - добавить элемент, 1000 - выход)"<<endl;
        cin>>i;
        if (i==0){
            cout<<"Введите значение удаляемого элемента"<<endl;
            cin>>i;
            delete_elem(root,i);
            print_tree(root,1);
        }
        if (i==1){
            cout<<"Введите значение элемента"<<endl;
            cin>>d;
            search_insert(root,d);
            print_tree(root,1);
        }     
    }
    cout<<"Удаление дерева"<<endl;
   deleteTree(&root);
   getchar();
   cout<<memfree()<<endl;
   getchar();
   //print_tree(root,1);
    
    return 0;
}