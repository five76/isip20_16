#include<iostream>
#include<fstream>
using namespace std;

void sort_array_string(string *a,int n)
{
    string temp;
    int j,t=0;
    for (int i=0;i<n;i++)
    {
        temp = a[i];
        for (j=i-1;j>=0 && a[j]>temp;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}

int main()
{
    const int n=100;
    int cu;
    string fam[n];
    string phone[n];
    int i=0;
    ifstream f;
    f.open("phonebook.txt");
    while(!f.eof())
    {
        getline(f,fam[i]);
        getline(f,phone[i]);
        cout<<fam[i]<<" "<<phone[i]<<endl;
        i++;
    }
    f.close();
    //cout <<"Phone user"<<endl;
    //cout<<fam[3]<<" "<<phone[3]<<endl;
    cu=i;
    cout<<"Sorting array"<<endl;
    sort_array_string(fam,cu);
    for (int i=0;i<n;i++)
    {
        cout<<fam[i]<<" "<<phone[i]<<endl;
    }
    return 0;
}