#include <stdio.h>
    #include <stdlib.h>
    #include<ctime>
    #include<fstream>
    #include<iostream>
    #include <bitset>
    #include<string.h>
    using namespace std;

    int main(){
        unsigned char c,c1;
        //bitset<256> k;
        string s="Help";
        string s1="Help";
        for (int k=0;k<s.size();k++){
            c=s[k];
            c1=s1[k];
            bitset<8> b1(c);
            bitset<8> b2(c);
            cout<<b1<<endl;
            cout<<b1[1];
            //k+=b1;
            getchar();
        }


        cout<<endl;
        cout<<strcmp("help","Help");
        //cout<<b1<<endl;
    }