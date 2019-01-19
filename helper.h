#ifndef HELPER_H
#define HELPER_H
#include<bits/stdc++.h>
using namespace std;

long long int powe(int ,int );

class area
{
	public:
		int x_cor;
		int y_cor;
	area(int ,int );
	int operator +(area const&obj);
};

class feedback
{
public:
	int * array;
	feedback()
		{
			array=new int[2];	
		}
        ~feedback()
		{
			delete []array;
		}
};

template<class T>
void view_details(T );

#endif
