#include<bits/stdc++.h>
#include"fruits.h"
#include"items.h"
using namespace std;

fruits::fruits()
    {
	location_x=0;
	location_y=0;
	unit_add=0;
	calories=0;
	price_unit=0;
    }

fruits::fruits (string type1,int location_x1,int location_y1,long double weight_unit1,int price_unit1,int calories1,int unit_add1,int p_id1,string p_time1)
    {
        type=type1;
        location_y=location_y1;
        location_x=location_x1;
        weight_unit=weight_unit1;
        price_unit=price_unit1;
        calories=calories1;
        unit_add=unit_add1;
        p_id=p_id1;
        p_time=p_time1;
    }

int fruits::get()
{
    return price_unit;
}

int fruits::geta()
{
    return unit_add;
}

int fruits::find(string str)
{
    int ans=0;
    if(type==str)
    return unit_add;
    return 0;
}

void fruits:: print()
{
    
    cout<<"Fruit Type: "<<type<<endl;
    cout<<"X Coordinate: "<<location_x<<endl;
    cout<<"Y Coordinate: "<<location_y<<endl;
    cout<<"Weight per Unit: "<<weight_unit<<endl;
    cout<<"Price per Unit: "<<price_unit<<endl;
    cout<<"Calories: "<<calories<<endl;
    cout<<"Unit_Add: "<<unit_add<<endl;
    cout<<"Purcahse ID: "<<p_id<<endl;
    cout<<"Purchase Time: "<<p_time<<endl;
    cout<<endl;
}

void fruits::area(int x,int y,int x1,int y1)
{
    if(location_x>=x && location_x<=x1)
    {
        if(location_y>=y && location_y<=y1)
        {
            cout<<type<<" "<<p_id<<endl;
            cout<<location_x<<" "<<location_y<<endl;
        }
    }
}
