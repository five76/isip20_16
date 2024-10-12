/*
Вычислить значение по следующим формулам при действительных значениях всех переменных
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    //Variables
    float x;
    float y;
    float f;

    //Input data
    cout<<"x?";
    cin>>x;
    cout<<"y?";
    cin>>y;
    

    //Calculate
    f = pow((1+1/pow(x,2)),x)-12*pow(x,2)*y;

    //Print result
    cout<<"f="<<f<<endl;


}

