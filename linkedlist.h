#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<bits/stdc++.h>

using namespace std;

class linkedlist
{
    
private:
    typedef struct node
    {
        items* ptr;
        node* next;
    }node_point;

	node_point *head,*tail;
    
public:
    linkedlist();
    void add_items(items * , bool );
    void printlist();
    void printlist(int );
    int search(string );
    void search_area(int ,int ,int ,int );
    void cal_max(int );
    void del(int );
    void sell(string ,int );
    void update(int ,int );
    friend class items;
};

#endif
