#include<iostream>
#include<fstream>
using namespace std;

struct PhoneBook
    {
        string fam;
        string phone;
    };

void sort_array_struct(PhoneBook *a,int n)
{
    PhoneBook temp;
    int j,t=0;
    for (int i=0;i<n;i++)
    {
        temp = a[i];
        for (j=i-1;j>=0 && a[j].fam>temp.fam;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}


string search_number(PhoneBook *a,string f1,int n)
{
    for (int i=0;i<n;i++)
    {
        if (f1 == a[i].fam)
            return a[i].phone;
    }
    return "Family not found";
}

int main()
{
    const int n=100;
    int cu;
    string search_fam;
    string s1(50,'*');
    PhoneBook contact[n];
    int i=0;
    ifstream f;
    f.open("phonebook.txt");
    while(!f.eof())
    {
        getline(f,contact[i].fam);
        getline(f,contact[i].phone);
        cout<<contact[i].fam<<" "<<contact[i].phone<<endl;
        i++;
    }
    f.close();
    cu=i;
    cout<<"Sorting data"<<endl;
    sort_array_struct(contact,cu);
    for (int i=0;i<cu;i++)
        cout<<contact[i].fam<<" "<<contact[i].phone<<endl;
    cout<<s1<<endl;
    cout<<"Enter family: ";
    cin>>search_fam;
    cout<<search_number(contact,search_fam,cu)<<endl;
    return 0;

}