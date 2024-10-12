#include <iostream>
#include <clocale>
#include <cmath>
#include <iomanip>
using namespace std;
#define pi 3.14 //определяем макропеременную pi
int main()
{
   
	setlocale(LC_CTYPE,"rus");
	const float eps=exp(-7.0);
	double xgrad,x,s,u;
	unsigned int n;
	cout<<"Введите значение угла: ";
	cin>>xgrad;
	x=xgrad*pi/180;//перевод угла в радианы
	s=x;u=x;n=1;
	while (abs(u)>eps)
	{
		n=n+2;// см. матем модель (**)
		u=-u*x*x/((n-1)*n);//вычисление очередного члена ряда см. матем модель(*)
		//каждый следующий член ряда вычисляется как произведение предыдущего u
		//на -x^2/((n-1)*n)
		s=s+u;
	}
	cout<<"Sin("<<xgrad<<")= "<<s<<endl;
}
