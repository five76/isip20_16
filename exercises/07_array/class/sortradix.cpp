    #include <stdio.h>
    #include <stdlib.h>
    #include<ctime>
    #include<fstream>
    #include<iostream>
    using namespace std;
     
     #define RADIX_10 10 // целочисленная сортировка
     
    /********************************************************
       * Название функции: печать
       * Описание параметра: массив неупорядоченный массив
       * длина массива length
       * Примечание: вывести содержимое массива
     *********************************************************/
    void print(unsigned int array[], int length) {
        for (int j = 0; j < length; j++) {
            printf(" %d ", array[j]);
        }
        printf("\n");
    }
     
    /********************************************************
       * Название функции: getLoopTimes
       * Описание параметра: число целочисленных данных
       * Описание: возвращает число из числа
     *********************************************************/
    int getLoopTimes(unsigned int num) {
        int count = 1;
        unsigned int temp = num / 10;
        while (temp != 0) {
            count ++;
            temp = temp / 10;
        }
        return count;
    }
     
    /********************************************************
       * Название функции: getMaxNum
       * Описание параметра: количество сортировок массива
       * длина массива length
       * Описание: вернуть максимальное значение
     *********************************************************/
    unsigned int getMaxNum(unsigned int array[], int length) {
        unsigned int max = 0;
        for (int i = 0; i < length; i++) {
            if (max < array[i]) {
                max = array[i];
            }
        }
        return max;
    }
     
    /********************************************************
       * Название функции: getNumInPos
       * Описание параметра: число целочисленных данных
       * pos указывает на данные о формировании, которые должны быть получены
       * Описание: Найдите данные pos-th от младшего до большего числа
     *********************************************************/
    int getNumInPos(int num, int pos) {
             // Находим делитель индекса сегмента, например: 798
             // индекс битовой корзины единиц = (798/1)% 10 = 8
             // Индекс сегмента десятков = (798/10)% 10 = 9
             // Индекс сегмента сотен = (798/100)% 10 = 7
        int temp = 1;
        for (int i = 0; i < pos - 1; i++) {
            temp *= 10;
        }
        return (num / temp) % 10;
    }
     
    /********************************************************
       * Название функции: radixSort
       * Описание параметра: массив неупорядоченный массив
       * длина массива length
       * Описание: Сортировка по мощности
     *********************************************************/
    void radixSort(unsigned int array[], int length) {
             // пространство последовательности 0 ~ 9 соответственно
        unsigned int *radixArrays[RADIX_10];
        for (int i = 0; i < RADIX_10; i ++) {
            radixArrays[i] = (unsigned int *)malloc(sizeof(unsigned int) * (length + 1));
                     radixArrays [i] [0] = 0; // Количество элементов, записанных в этой группе данных с нижним индексом 0
        }
             // Получаем максимальное число в массиве
        unsigned int maxNum = getMaxNum(array, length);
             // Получаем максимальное количество цифр, которое также является количеством перераспределений
        int loopTimes = getLoopTimes(maxNum);
             // Назначаем каждый бит
        for (int pos = 1; pos <= loopTimes; pos ++) {
                     // Процесс распределения
            for (int i = 0; i < length; i ++) {
                int num = getNumInPos(array[i], pos);
                int index = ++ radixArrays[num][0];
                radixArrays[num][index] = array[i];
            }
                     // Процесс сбора
            for (int i = 0, j = 0; i < RADIX_10; i ++) {
                for (int k = 1; k <= radixArrays[i][0]; k ++) {
                    array[j++] = radixArrays[i][k];
                }
                             radixArrays [i] [0] = 0; // сбрасываем
            }
                     // вывод содержимого массива
           // print(array, length);
        }
    }
     
    int main(int argc, const char * argv[]) {
        double t1,sum_t1;
        double t2,sum_t2;
        clock_t tStart;
        ifstream f;
        int i;
        int n;
        f.open("data.txt");
        f>>n;

        unsigned int *radixArray = new unsigned int[n];
        //unsigned int radixArray[5024];//= { 73, 22, 93, 43, 55, 14, 28, 65, 39, 81 ,12};
        i=0;
        //tStart = clock(); 
        while (!f.eof()){
            f>>radixArray[i];
            i++;
        }
        f.close();
        tStart = clock(); 
        radixSort(radixArray, n);
        t1 = (double)(clock() - tStart)/CLOCKS_PER_SEC;
        printf("Сортировка заняла: %.7fs\n", t1);
        //print(radixArray, n);
        delete [] radixArray;
        return 0;
    }