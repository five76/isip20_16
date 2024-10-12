#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

string delete_start_space(string s)
{
    string t="";
    for (int i=0;i<s.size();i++)
    {
        if (s[i]!=' ')
            return s.substr(i);
    }
}


string delete_space2(string s)
{
    string t="";
    for (int i=0;i<s.size();i++)
    {
        if (s[i]!=' ' ||  (s[i]==' ' && s[i+1]!=' '))
            t.append(1,s[i]);
    }
    return t;
}

string delete_space(string s)
{
    s = delete_start_space(s);
    string t="";
    for (int i=0;i<s.size();i++)
    {
        if (s[i]!=' ' ||  (s[i]==' ' && s[i+1]!=' '))
            t.append(1,s[i]);
    }
    return t;
}

int count_char_of_string(string s)
{
    string t="";
    for (int i=0;i<s.size();i++)
    {
        if (t.find(s[i],0)==-1)
            t.append(1,s[i]);
    }
    cout<<t<<endl;
    return t.size();
}

int main()
{
    string s1;
    ifstream f;
    clock_t tStart;
    f.open("data.txt");
    tStart=clock();
    while (!f.eof())
    {
        getline(f,s1);
        //cout<<s1<<endl;
        //cout<<count_char_of_string(s1)<<endl;
        cout<<delete_space(s1)<<endl;
    }
    printf("Time working: %.5fs\n",(double)(clock()-tStart)/CLOCKS_PER_SEC);
    f.close();

    return 0;
}
