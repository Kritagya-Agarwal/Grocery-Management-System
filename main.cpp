#include<bits/stdc++.h>
#include"items.h"
#include"linkedlist.h"
#include"fruits.h"
#include"vege.h"
#include"helper.h"

using namespace std;

template<class T>
void view_details(T product)
{
	product.print();
}

int main()
{
    int pur_id=1;
    linkedlist obj;
    FILE *f1=fopen("fruits.txt","r");
    if(f1==NULL)
    {
        printf("File is not created");
    }
    else
    {
    	cout<<"Fruits File read"<<endl;
        int count=0;
        char carry[200];
    	string temp;
    	double str[6];
    	int index=0;
    	int arr =0;
    	long double ktemp=0;
        while(fscanf(f1,"%s ",carry)!=EOF)
        {
        	time_t now=time(0);
        	string t_ime=ctime(&now);    
        	if(count==0)
        		temp=carry;
        	else
        	{
            		int n=strlen(carry);
            		int pos=-1;
            		long long int ans=0;
            		int val=1;            
            		if(count==3)
            		{
                		long double ko=0.0;
                		for(int i=0;i<n;i++)
                		{
                    			if(carry[i]=='.')
                        		{
                        			pos=i;
                        			break;
                        		}
                		}
                
                		for(int i=n-1;i>=0;i--)
                		{
                    			if(i!=pos)
                    			{
                    				ko+=val*(carry[i]-48);
                    				val=val*10;
                    			}
                		}
			if(pos!=-1)
                		ktemp=ko/(powe(10,n-1-pos));
			else
				ktemp=ko;    
            		}
            		else
            		{
                		for(int i=n-1;i>=0;i--)
                		{
                    			ans+=val*(carry[i]-48);
                    			val=val*10;
                		}
            		}	    
            		str[arr++]=ans;    
        	}
        count++;
        if(count==7)
        {
        	fruits a(temp,str[0],str[1],ktemp,str[3],str[4],str[5],pur_id++,t_ime);
        	obj.add_items(&a,1);       
            	index++;
            	arr=0;
            	count=0;
        }
            
        }
    }
    fclose(f1);
    printf("\n");
    FILE *f2=fopen("vegetables.txt","r");
    if(f2==NULL)
    {
        printf("File is not created");
    }
    else
    {
    	cout<<"Vegetables file read"<<endl;
    	int count=0;
    	char carry[200];
    	string temp;
    	int str[6];
    	int index=0;
    	int arr =0;
    	long double ktemp=0;
        while(fscanf(f2,"%s ",carry)!=EOF)
        {
        	time_t now=time(0);
        	string t_ime=ctime(&now);
        	if(count==0)
        		temp=carry;
        	else
        	{
            		int n=strlen(carry);
            		int pos=-1;
            		long long int ans=0;
            		int val=1;            
            		if(count==4)
            		{
                		long double ko=0.0;
                		for(int i=0;i<n;i++)
                		{
                    			if(carry[i]=='.')
                        		{
                        			pos=i;
                        			break;
                        		}
                		}
                
                		for(int i=n-1;i>=0;i--)
                		{
                    			if(i!=pos)
                    			{
                    				ko+=val*(carry[i]-48);
                    				val=val*10;
                    			}
                		}
				if(pos!=-1)
                			ktemp=ko/(powe(10,n-1-pos));
				else
					ktemp=ko;    
            			}
            		else
            		{
                		for(int i=n-1;i>=0;i--)
                		{
                    			ans+=val*(carry[i]-48);
                    			val=val*10;
                		}
            		}    
            		str[arr++]=ans;      
        	}
        count++;
        if(count==7)
        {
        	vegetables n(temp,str[0],str[1],str[2],ktemp,str[4],str[5],pur_id++,t_ime);
            	obj.add_items(&n,0);        
            	index++;
            	arr=0;
            	count=0;
        }
            
        }
    }
	    cout<<endl;
	    cout<<" Given is the list of functions available: "<<endl;
	    cout<<" Enter 1 : To add fruits in the system"<<endl;
	    cout<<" Enter 2 : To add vegetables in the system"<<endl;
	    cout<<" Enter 3 : To display list of all items"<<endl;
	    cout<<" Enter 4 : To purchase an item from grocery shop"<<endl;
	    cout<<" Enter 5 : To find items in given area"<<endl;
	    cout<<" Enter 6 : To search number of units available for fruit/vegtable"<<endl;
	    cout<<" Enter 7 : To purchase maximum items available corresponding to given calorie"<<endl;
	    cout<<" Enter 8 : To add feedback "<<endl;
	    cout<<" Enter 9 : To check whether input in system is correct for fruits"<<endl;
	    cout<<" Enter 10 : To check whether input in system is correct for vegetables"<<endl;
	    cout<<" Enter 12 : To display details of particular Purchase ID: "<<endl;
	    cout<<" Enter 0 : To exit"<<endl;
	    int state=1;
    	while(1)
    	{
	    	cout<<"Enter Choice :"<<endl;
	    	int state;
	    	cin>>state;
	    	if(state==0)
	    		break;
	    	if(state==1)
	    	{
	    		cout<<"Enter the number of fruits you wish to add: "<<endl;
	    		int fruits_n;
	    		cin>>fruits_n;
	    		for(int i=0;i<fruits_n;i++)
	    		{
	    			time_t now=time(0);
				string t_ime=ctime(&now);
				cout<<"Type details "<<i+1<<endl;
				string type;
	    			int inf_1,inf_2,inf_4,inf_5,inf_6;
	    			long double inf_3;
				cin>>type>>inf_1>>inf_2>>inf_3>>inf_4>>inf_5>>inf_6;
				fruits a(type,inf_1,inf_2,inf_3,inf_4,inf_5,inf_6,pur_id++,t_ime);
				obj.add_items(&a,1);
	    		}
	    		cout<<endl;
	    	}
	    	if(state==2)
	    	{
	    		cout<<"Enter the number of vegetables you wish to add: "<<endl;
	    		int vege_n;
	    		cin>>vege_n;
	    		for(int i=0;i<vege_n;i++)
	    		{
	    			time_t now=time(0);
				string t_ime=ctime(&now);
				cout<<"Type details "<<i+1<<endl;
				string type;
			    	int inf_1,inf_2,inf_4,inf_5,inf_6;
			    	long double inf_3;
				cin>>type>>inf_1>>inf_2>>inf_4>>inf_3>>inf_5>>inf_6;
				vegetables b(type,inf_1,inf_2,inf_4,inf_3,inf_5,inf_6,pur_id++,t_ime);
			    	obj.add_items(&b,0);
			    }
	    		cout<<endl;
	    	}
    		if(state==6)
    		{
    			cout<<"Enter the type of fruit/vegetable to search"<<endl;
    			string fru_type;
    			cin>>fru_type;
    			int answer=obj.search(fru_type);
    			cout<<"Number of Units are: "<<answer<<endl;
    			cout<<endl;
    		}
    		if(state==3)
    		{
    			obj.printlist();
    			cout<<endl;
    		}
    		if(state==5)
    		{
		    cout<<"Enter the lower bound and upper bound of x:"<<endl;
		    int low_x,high_x;
		    cin>>low_x>>high_x;
		    cout<<"Enter the lower bound and upper bound of y:"<<endl;
		    int low_y,high_y;
		    cin>>low_y>>high_y;
		    area first(low_x,low_y);
		    area second(high_x,high_y);
		    cout<<"Area of Given Region: "<<first+second<<endl;
		    cout<<endl;
		    cout<<"Units Found are: "<<endl;
		    obj.search_area(low_x,low_y,high_x,high_y);
		    cout<<endl;
		}
		if(state==7)
		{
		    cout<<"Enter the number of calories :"<<endl;
		    int calo;
		    cin>>calo;
		    obj.cal_max(calo);
		    cout<<endl; 
		}
		if(state==4)
		{ 
		    cout<<"Enter the type fruit/vegtable to purchase:"<<endl;
		    string sell_type;
		    cin>>sell_type;
		    int limit=obj.search(sell_type);
		    cout<<"Enter the units to purcahse: Limit for this type is "<<limit<<endl;
		    int num_count;
		    cin>>num_count;
		    if(num_count>limit)
		    	cout<<"Not enough units present in store"<<endl;
		    else
		    	obj.sell(sell_type,num_count);
		    cout<<endl;
		}
		if(state==12)
		{
		    cout<<"Enter Purchase I_D to display its details: "<<endl;
		    int ID;
		    cin>>ID;
		    obj.printlist(ID);
		}
		if(state==8)
		{
		    feedback feed;
		    cout<<"Please add your review (Out of 5)"<<endl;
		    int service;
		    int Clean;
		    cout<<"For Service: "<<endl;
		    cin>>service;
		    feed.array[0]=service;
		    cout<<"For Cleanliness in store: "<<endl;
		    cin>>Clean;
		    feed.array[1]=Clean;
		    cout<<endl;
		}
		if(state==9)
		{
		    time_t now=time(0);
		    string t_ime=ctime(&now);
		    cout<<endl;  
		    cout<<"Add a fruit details (To check if program is taking correct Input): "<<endl;
		    string type;
		    int inf_1,inf_2,inf_4,inf_5,inf_6;
		    long double inf_3;
		    cin>>type>>inf_1>>inf_2>>inf_3>>inf_4>>inf_5>>inf_6;
		    fruits ap(type,inf_1,inf_2,inf_3,inf_4,inf_5,inf_6,pur_id++,t_ime);
		    view_details<fruits>(ap);
		    pur_id--;
		    cout<<endl;
		}
		if(state==10)
		{
		    time_t now=time(0);
		    string t_ime=ctime(&now);
		    cout<<"Add a Vegetable details (To check if program is taking correct Input): "<<endl;
		    int inf_7;
		    string type;
		    int inf_1,inf_2,inf_4,inf_5,inf_6;
		    cin>>type>>inf_1>>inf_2>>inf_7>>inf_4>>inf_5>>inf_6;
		    vegetables bp(type,inf_1,inf_2,inf_7,inf_4,inf_5,inf_6,pur_id++,t_ime);
		    cout<<1<<endl;
		    view_details<vegetables>(bp);
		    pur_id--;
		    cout<<endl;
		}
	}
}
