#include "sostav.cpp"
#include <fstream>


int main(){
    int n,t;
    ifstream(f);
    f.open("vagon.txt");
    f>>n>>t;
    Sostav  cis(n,t);  //создание класса состав с цистернами
    f>>n>>t;
    Sostav cont(n,t);  //состав с контейнерами
    while (!f.eof()){
        f>>n>>t;
        if (t){
            cis.push_sostav(&cont.p,n,t);
            cont.c++;
        }
        else{   
            cis.push_sostav(&cis.p,n,t);
            cis.c++;
        }
    }
    cis.print_sostav(&cis.p);
    cout<<"\nВ составе цистерн "<<cis.c<<endl;
    cis.print_sostav(&cont.p);
    cout<<"\nВ составе контейнеров "<<cont.c<<endl;
    cout<<endl;
    f.close();
}