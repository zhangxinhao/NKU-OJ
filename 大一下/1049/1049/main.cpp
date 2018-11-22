//
//  main.cpp
//  1049: C++ 第七章作业一
//
//  Created by apple on 2017/4/17.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
using namespace std;

struct node
{
    int date;
    node * next;
};

class list
{
public:
    list(int k)
    {
        head= new node;
        head->next=NULL;
        head->date=k;
    }
    ~list()
    {
        delete head;
    }
    node *head;
    void insert(int n);
    void print();
    
};

void list::insert(int n)
{
    int temp;
    node * pnew,* ptemp;
    ptemp=head;
    pnew= new node;
    
    if (n < head->date) {
        temp=head->date;
        head->date=n;
        head->next=pnew;
        pnew->date=temp;
        pnew->next=NULL;
        return;
    }
    
    while (ptemp->next != NULL) {
        if (n >= ptemp->date) {
            ptemp = ptemp->next;
            continue;
        }
        temp = ptemp->date;
        ptemp->date = n;
        pnew->date=temp;
        pnew->next=ptemp->next;
        ptemp->next=pnew;
        
    }
    if (ptemp->next==NULL) {
        if (n >= ptemp->date) {
            ptemp->next=pnew;
            pnew->date=n;
            pnew->next=NULL;
            return;
        }
        temp = ptemp->date;
        ptemp->date = n;
        pnew->date=temp;
        pnew->next=NULL;
        ptemp->next=pnew;
    }
    
}

void list::print()
{
    node *p = head;
    while (p->next != NULL) {
        cout << p->date<<" ";
        p=p->next;
    }
    cout << p->date<<" ";
}

int judge(int k)
{
    int n= k/2;
    int i;
    if (k==2) {
        return 1;
    }
    for (i=2; i<n; i++) {
        if (k%i==0) {
            return 0;
        }
        
    }
    return 1;
}

int main() {
    int k;
    cin>>k;
    list a(k);
    cin>>k;
    while (judge(k)) {
        a.insert(k);
        cin>>k;
    }
    a.print();
    return 0;
}
