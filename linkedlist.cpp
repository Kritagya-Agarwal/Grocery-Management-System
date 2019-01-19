#include<bits/stdc++.h>
#include"items.h"
#include"linkedlist.h"
#include"fruits.h"
#include"vege.h"
using namespace std;

linkedlist::linkedlist()
    {
    	
        head=NULL;
        tail=NULL;
    }

struct array
{
    int price,count,pur_id;
};
typedef struct array root;

bool cmp(root a,root b)
{
    return a.price<b.price;
}
void linkedlist::update(int id,int val)
{
    node_point * temp=head;
    while(temp!=NULL)
    {
        if(temp->ptr->p_id==id)
        {
            temp->ptr->unit_add=val;
            break;
        }
        temp=temp->next;
    }
}

void linkedlist::sell(string s,int cbnt)
{
    long long int cost=0;    
    node_point *temp=head;
    if(head==NULL)
    	cout<<"Empty List"<<endl;
    else
    {
        int cnt=cbnt;
        while(cnt!=0)
        {
        	int mi=100000000;
		temp=head;
        while(temp!=NULL)
        {
            if(temp->ptr->type==s)
            	mi=min((temp->ptr->location_x)*(temp->ptr->location_x)+(temp->ptr->location_y)*(temp->ptr->location_y),mi);
            	temp=temp->next;        
        }
        temp=head;
	int r=0;
        while(temp!=NULL)
        {
            if((temp->ptr->location_x)*(temp->ptr->location_x)+(temp->ptr->location_y)*(temp->ptr->location_y)==mi)
            {
                r++;        
            }
            temp=temp->next;
        }
        temp=head;
        int index=0;
        root arr[r];
        while(temp!=NULL)
        {
            if((temp->ptr->location_x)*(temp->ptr->location_x)+(temp->ptr->location_y)*(temp->ptr->location_y)==mi)
                {
                    arr[index].price=temp->ptr->get();
                    arr[index].pur_id=temp->ptr->p_id;
                    arr[index].count=temp->ptr->geta();
			index++;
                }
            temp=temp->next;
        }
        sort(arr,arr+r,cmp);
        for(int i=0;i<r;i++)
        {
            if(cnt==0)
            break;
            if(arr[i].count>cnt)
            {
                cost+=cnt*arr[i].price;
		update(arr[i].pur_id,arr[i].count-cnt);
                cnt=0;               
            }
            else 
            {
                cost+=arr[i].count*arr[i].price;         
                cnt-=arr[i].count;
                del(arr[i].pur_id);            
            }    
        }
     	}                    
    }
    cout<<"Total Cost is: "<<cost<<endl;
    cout<<endl;
}

void linkedlist::del(int p_d)
{
    node_point *temp=head;
    if(head==NULL || tail==NULL)
    cout<<"Empty List"<<endl;
    else
    {
        if(temp->ptr->p_id==p_d)
        {
            head=temp->next;
            delete temp ;
        }
        else
        {    
            while(temp->next->ptr->p_id!=p_d)
            {
                temp=temp->next;
            }
            if(temp->next->next==NULL)
            {
                node_point *utemp=temp;
                temp->next=NULL;
                delete utemp->next;
                tail=temp;
            }
            else
            {
                node_point *utemp=temp->next;
                temp->next=temp->next->next;
                delete utemp;
            }
        }
    }

}

struct t
{
	int calorie,count,id;
	string typ;
};
typedef struct t block;

bool cp(block a,block b)
{
	return a.calorie<b.calorie;
}
 
void linkedlist::cal_max(int cal)
{
    int temp=-1;
    int max=0;
    int present=0;
    if(head==NULL)
    {
        cout<<"Empty List"<<endl;
    }
    node_point* emp=head;
    int cnt=0;
    while(emp!=NULL)
    {
     	cnt++;
	emp=emp->next;
    }
    emp=head;
    block ar[cnt];
    int index=0;
    while(emp!=NULL)
    {
	ar[index].calorie=emp->ptr->calories;
	ar[index].id=emp->ptr->p_id;
	ar[index].count=emp->ptr->unit_add;
	ar[index].typ=emp->ptr->type;
	index++;
	emp=emp->next;
    }
    int size=index;
    sort(ar,ar+cnt,cp);
    index=0;
    while(cal!=0 && index<size)
    {
	if(ar[index].calorie*ar[index].count<=cal)
		{
			temp=0;
			cal-=ar[index].calorie*ar[index].count;
			cout<<"Purcahse ID "<<ar[index].id<<endl;
			cout<<"Type "<<ar[index].typ<<endl;
			cout<<"Unit Taken "<<ar[index].count<<endl;
			cout<<"Calories per unit: "<<ar[index].calorie<<endl;
			cout<<endl;			
			del(ar[index].id);
		}
	else if(ar[index].calorie*ar[index].count>cal)
		{
			int rest=cal/ar[index].calorie;
			if(rest==0)
				cal=0;
			else
				{
					temp=0;
					cout<<"Purcahse ID "<<ar[index].id<<endl;
					cout<<"Type "<<ar[index].typ<<endl;
					cout<<"Unit Taken "<<rest<<endl;
					cout<<"Calories per unit: "<<ar[index].calorie<<endl;
					cout<<endl;;
					update(ar[index].id,ar[index].count-rest);
					cal=0;
				}
		}
	index++;
    } 

    if(temp==-1)
	cout<<"No item found"<<endl; 
}

int linkedlist::search(string str)
{
    int ans=0;
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        node_point* temp=head;
    	int available=0;
        while(temp!=NULL)
        {
            available=temp->ptr->find(str);
            ans+=available;    
            temp=temp->next;
        }
    }
    return ans;
}

void linkedlist::search_area(int x,int y,int x1,int y1)
{
    if(head==NULL)
    {
        cout<<"Empty List"<<endl;
    }
    else
    {
        node_point * temp=head;
        while(temp!=NULL)
        {
            temp->ptr->area(x,y,x1,y1);
            temp=temp->next;
        }
    }
}

void linkedlist::add_items(items * temp,bool stat)
{
    node_point *tmp;
    tmp=new struct node;
    if(stat)
    	tmp->ptr=new fruits(temp->type,temp->location_x,temp->location_y,temp->weight_unit,temp->price_unit,temp->calories,temp->unit_add,temp->p_id,temp->p_time);
    else
    	tmp->ptr=new vegetables(temp->type,temp->location_x,temp->location_y,temp->price_kg,temp->volume_kg,temp->calories,temp->unit_add,temp->p_id,temp->p_time);
    tmp->next=NULL;  
    if(head==NULL)
    {
        head=tmp;
        tail=tmp;
    }
    else
    {
        tail->next=tmp;
        tail=tail->next;
    }
}

void linkedlist::printlist()
{
    if(head==NULL)
    {
        cout<<"Empty List"<<endl;
    }
    else
    {
        node_point* temp =head;
        while(temp!=NULL)
        {
            temp->ptr->print();
            temp=temp->next;
        }
    }
    
};

void linkedlist::printlist(int id)
{
	if(head==NULL)
		cout<<"Empty List"<<endl;
	else
	{
		int tem=0;
		node_point* temp=head;
		while(temp!=NULL)
		{
			if(temp->ptr->p_id==id)
			{
				tem=1;
				temp->ptr->print();
				break;
			}
			temp=temp->next;
		}
		if(tem==0)
		{
			cout<<"Purchase ID doesnot exist"<<endl;
		}	
	}
}

