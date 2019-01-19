#ifndef VEGE_H
#define VEGE_H
#include<bits/stdc++.h>
#include"items.h"
using namespace std;

class vegetables: public items
{
public:
    vegetables();
    vegetables (string ,int ,int ,int ,long double ,int ,int ,int ,string );
private:
    void print();    
    int find(string );
    void area(int ,int ,int ,int ); 
    int get();
    int geta();
    template<class T>
    friend void view_details(T );
    
};

#endif
