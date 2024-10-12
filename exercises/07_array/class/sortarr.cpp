#include <iostream>
#include <ctime>
using namespace std;

void sort_enum(int *B, int n){
    //Сортировка массива "вставкой"
    int index_min;
    int temp;
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
            }
        }
}

void sort_insert(int *A, int n)
{
    int temp;
    int i;
    int j;
    for (i = 0; i < n;i++){
        temp=A[i];
        for (j = i-1; j>=0 && A[j]>temp;j--)
        {
            A[j+1]=A[j];
        }
        A[j+1]=temp;
    }
}

int find_min(int *A, int n)
{
    int i;
    int min;
    min=A[0];
    for (i=0;i<n;i++)
    {
        if (A[i]<min)
            min=A[i];
    }
    return min;
}

int main()
{
const int n=100000;                                      //константа, задающая количество элементов массива
const int k=100;
   int B[n];                                            //Массив из n элементов
   int A[n];
   int index_min;                                       //индекс для минимального элемента
   double t1,sum_t1;
   double t2,sum_t2;
   clock_t tStart;
   int i;
    int ii;
 
    //генерация элементов массива [-100;100]
  //  srand(time(0));
    //for (ii=0;ii<k;ii++){
        srand(time(0));
        for (i=0;i<n;i++)
        {
            A[i]=-100+rand()%200;
            B[i]=A[i];
        }
        
        //Поиск мин для неотсорт масс
        tStart = clock();  
        find_min(A, n);
        t1 = (double)(clock() - tStart)/CLOCKS_PER_SEC;
        printf("Поиск мин элемента занял: %.15fs\n", t1);
        
        //Сортировка массива
        tStart = clock();  
        sort_insert(A, n);
        t1 = (double)(clock() - tStart)/CLOCKS_PER_SEC;
        //printf("Сортировка заняла: %.8fs\n", t1);
        //sum_t1+=t1;

        //Поиск мин для сорт масс
        tStart = clock();  
        find_min(A, n);
        t1 = (double)(clock() - tStart)/CLOCKS_PER_SEC;
        printf("Поиск мин элемента занял: %.15fs\n", t1);



/*
        tStart = clock();  
        sort_enum(B, n);
        t2 = (double)(clock() - tStart)/CLOCKS_PER_SEC;
        //printf("Сортировка заняла: %.8fs\n", t2);
        sum_t2+=t2;
 //   }
   // t1 = sum_t1/double(k);
    //t2 = sum_t2/double(k);
    //printf("Среднее время сортировки: %.3fs\n", t1);
    //printf("Среднее время сортировки:: %.3fs\n", t2);
*/

    return 0;
}



