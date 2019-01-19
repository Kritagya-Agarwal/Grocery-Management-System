#include<bits/stdc++.h>
#include"helper.h"
#include"fruits.h"
#include"vege.h"
using namespace std;

long long int powe(int var,int power)
{
    if(power==0)
        return 0;
    long long int ans=1;
    long long int value=var;
    for(int i=0;i<32;i++)
    {
        if((power>>i)&1)
            {
                ans*=value;
            }
        value=value*value;
    }
    return ans;
}

area::area(int x,int y)
	{
		x_cor=x;
		y_cor=y;
	}

int area::operator +(area const&obj)
	{
		int region=(obj.x_cor-x_cor)*(obj.y_cor-y_cor);
		return region;
	}

template<class T>
void view_details(T product)
{
	product.print();
}
