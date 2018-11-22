//
//  main.cpp
//  数位提取
//
//  Created by apple on 2016/12/8.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
using namespace std;
int i=0;
int fun_lr(unsigned long x, int n,int &Lxn);
int main()
{
    unsigned long x;
    int n,Lxn;
    cin>>x>>n;
    fun_lr(x,n,Lxn);
    cout<<fun_lr(x,n,Lxn)<<" "<<Lxn;
    return 0;
}
int fun_lr(unsigned long x, int n,int &Lxn)
{
    unsigned long t=x,j=x,q=x,k=1;
    for (i=1; i<n; i++) {
        t=t/10;
    }
    t%=10;
    while((j/=10)!=0)
    {
        k++;
    }
    if(n>k)
    {
        Lxn=0;
        return 0;
    }
    for (i=1; i<=(k-n); i++) {
        q=q/10;
    }
    q%=10;
    Lxn=q;
    return t;
}
