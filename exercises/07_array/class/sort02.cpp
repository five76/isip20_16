#include <iostream>
#include <ctime>
using namespace std;

int main()
{
   const int n=10000;                                      //константа, задающая количество элементов массива
   int B[n];//={87,45,30,85,61,40,45,39,84,45};    //Массив из n элементов
   int index_min;                                       //индекс для минимального элемента
   int temp;
   int cb=0;       
   clock_t tStart;
    int i;

    srand(time(0));
    //генерация элементов массива [-100;100]
    for (i=0;i<n;i++)
    {
        B[i]=-100+rand()%200;
    }
    tStart = clock();  
   //Сортировка массива "вставкой"
   for (int i = 0; i < n-1;i++){
        index_min=i;                    //За минимальный берем первый из неотсортированных
        for (int j = i+1; j < n;j++)  //Начинаем проверять с последующего за ним элемента все оставшиеся
        {
            if (B[j]<B[index_min])      //если какой-то из них меньше,...
            {
               index_min=j;             //...то запоминаем его номер
            }
        }
        if (index_min!=i){              //если в ходе проверки индекс минимального элемента поменялся
                temp=B[i];              //то меняем местами элементы
                B[i]=B[index_min];
                B[index_min]=temp;
                cb++;                   //увеличиваем счетчик замен

        }
    }
    printf("Сортировка заняла: %.8fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
/*
 //Вывод массива
    for (int i = 0; i < n;i++){
        cout<<B[i]<<" ";
    }
cout<<endl;
*/

cout<<"Count "<<cb<<endl;
return 0;
}