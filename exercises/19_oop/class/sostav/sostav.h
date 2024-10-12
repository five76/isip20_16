#include<iostream>
#include<string>
struct Vagon{
            int number;
            short int typ;
            Vagon * next;
        };

class Sostav{
    //private:
      //  int c;   //количество вагонов в составе
    public:
        //int count;  
        Sostav(int _number,short int _typ);
        Vagon * push_sostav(Vagon ** top,int _number,short int _typ);
        void print_sostav(Vagon ** top) const;
        //int get_count() {return count;};
        ~Sostav();
        Vagon * p;
    public:
        int c;
};
