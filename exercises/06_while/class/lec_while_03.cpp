#include <iostream>
#include <cmath>
#include<stdio.h>
using namespace std;
#define pi 3.14             //макропеременная pi

int main()
{
   
	float x,y,z,a,b,dx;
	cout<<"Введите начальное значение аргумента: ";
	cin>>a;
	cout<<"Введите конечное значение аргумента: ";
	cin>>b;
	cout<<"Введите шаг изменения аргумента: ";
	cin>>dx;
	x=a;                    //начальное значение переменной цикла
	while (x<=b)
	{
	   z=sin((pi*x)/3);
	   if (z<0) cout<<"f("<<x<<") = Функция не определена"<<endl;   //действительного корня из числа меньше 0 нет
	   else
	   {
			y=log10(3.0)+x*sqrt(5.0*z);
			printf("f(%5.2f) = %5.2f\n",x,y);
	   }
	   x+=dx; //x=x+dx Увеличение значения аргумента
	}
    return 0;
}
