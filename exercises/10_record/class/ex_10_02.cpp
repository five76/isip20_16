/*
Из имеющегося списка спортсменов распечатать данные о тех из них, кто занимается плаванием. 
Указать возраст и сколько лет они занимаются спортом.
Сведения должны располагаться в текстовом файле data_sport.txt в следующем формате:
фамилия
дата рождения
вид спорта
дата начала занятия спортом
*/


#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <stdio.h>
using namespace std;

struct Sportsman {
    string fam;     //фамилия
    string dr;         //дата рождения
    int age;            //возраст
    string sport_type;  //вид спорта
    string ds;          // дата начала занятий спортом
    int age_sport;      //спортивный стаж
};

void print_format(Sportsman a)      //функция для печати в заданном формате
{
   
}

int calc_age(string dr)
{
    
}

 
int main()
{ 
   
    return 0;
}
