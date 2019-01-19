#include<bits/stdc++.h>
#include"vege.h"
#include"items.h"
using namespace std;

vegetables::vegetables()
    {
	location_x=0;
	location_y=0;
	unit_add=0;
	calories=0;
	price_unit=0;
    }

vegetables::vegetables (string type1,int location_x1,int location_y1,int price_kg1,long double volume_kg1,int calories1,int unit_add1,int p_id1,string p_time1)
    {
        type=type1;
        location_y=location_y1;
        location_x=location_x1;
        price_kg=price_kg1;
        volume_kg=volume_kg1;
        calories=calories1;
        unit_add=unit_add1;
        p_id=p_id1;
        p_time=p_time1;
    }

int vegetables::get()
{
    return price_kg;
}

int vegetables::geta()
{
    return unit_add;
}

void vegetables::area(int x,int y,int x1,int y1)
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

void vegetables:: print()
{
    cout<<"Vegetable Type: "<<type<<endl;
    cout<<"X Coordinate: "<<location_x<<endl;
    cout<<"Y Coordinate: "<<location_y<<endl;
    cout<<"Price per Kg: "<<price_kg<<endl;
    cout<<"Volume per Kg: "<<volume_kg<<endl;
    cout<<"Calories: "<<calories<<endl;
    cout<<"Unit_Add: "<<unit_add<<endl;
    cout<<"Purcahse ID: "<<p_id<<endl;
    cout<<"Purchase Time: "<<p_time<<endl;
    cout<<endl;
}

int vegetables::find(string str)
{
    int ans=0;
    if(type==str)
    return unit_add;
    return 0;
}
