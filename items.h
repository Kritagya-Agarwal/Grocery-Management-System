#ifndef ITEMS_H
#define ITEMS_H
#include<bits/stdc++.h>
using namespace std;

class items
{
protected:
    int p_id;
    int location_x;
    int location_y;
    string p_time;
    int calories; 
    int unit_add;
    long double weight_unit;
    int price_unit; 
    int price_kg;
    long double volume_kg;
    string type;
    virtual void print(){}
    virtual void area(int ,int ,int ,int ){}
    virtual int calc(int ){}
    virtual int find(string ){}
    virtual int get(){}
    virtual int geta(){}
public:
    items();
    items(int ,int ,int ,string );
    friend class linkedlist;
};

#endif
