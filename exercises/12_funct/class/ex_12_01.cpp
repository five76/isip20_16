/*
Вычислить значение по следующим формулам при действительных значениях всех переменных.
Вычисление результата должно быть выполнено в функции result 
*/
#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

//...

double result(float x, float y)
{
  double f = 0.0;
  f = pow((1+1/(x*x)),x)-12*x*x*y;
  return f;
} 

int main()
{
  float x,y;
  cout<<"Введите значения переменных x и y"<<endl;
  cin>>x>>y;
  printf("f = %5.2f\n",result(x,y));
  return 0;
}


