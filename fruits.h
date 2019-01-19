#ifndef FRUITS_H
#define FRUITS_H
#include<bits/stdc++.h>
#include"items.h"
using namespace std;

class fruits: public items
{
public:
    fruits();
    fruits (string ,int ,int ,long double ,int ,int ,int ,int ,string );
private:
    int find(string );
    void print();
    void area(int ,int ,int ,int );
    int get();
    int geta();
    template<class T>
    friend void view_details(T );
    
};

#endif
