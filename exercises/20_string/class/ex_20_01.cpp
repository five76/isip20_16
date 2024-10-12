#include <string>
#include <iostream>
using namespace std;
 
int main()
{
    string s1 = "hello";
    string s2 = "World";
    string hello = s1 + " " + s2 + "!!!";
    string s4(50,'*');
    string s5;
    cout << hello << "\n";
    cout << s4 << "\n";
    //--------------------------------
    cout<<s1.size()<<endl;
    cout<<s2.size()<<endl;
    cout<<hello.size()<<endl;
    cout<<hello[0]<<" "<<hello[hello.size()-1];

    cout<<"Введите произвольную строку"<<endl;
    getline(cin,s5);
    cout<<"Вы ввели:"<<s5<<endl;

    return 0;
}