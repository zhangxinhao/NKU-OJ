//
//  main.cpp
//  1082: 进制转换
//
//  Created by apple on 2016/12/8.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
using namespace std;
int i=0,j,k=0;
char ch;
int str[100];
int str1[100];
int str2[100];
unsigned int m;
int x;
void IntTenToX(unsigned int m, int x)
{
    unsigned int a=m;
    k=0,i=0;
    while (a!=0) {
        str[i]=a%2;
        i++;
        a/=2;
    }
    if (x==2) {
        cout<<m<<"(2)=";
        for (j=i-1; j>=0; j--)
        {
            cout<<str[j];
        }
        cout<<endl;
    }
    if (x==8) {
        cout<<m<<"(8)=";
        for (j=0; j<=i-1; j+=3,k++) {
            str1[k]=str[j+2]*4+str[j+1]*2+str[j];
        }
        for (k=k-1; k>=0; k--)
        {
            cout<<str1[k];
        }
        cout<<endl;
    }
    if (x==16) {
        cout<<m<<"(16)=";
        for (j=0; j<=i-1; j+=4,k++) {
            str2[k]=str[j+3]*8+str[j+2]*4+str[j+1]*2+str[j];
        }
        for (k=k-1; k>=0; k--)
        {
            if(str2[k]>9)
            {
                ch=str2[k]+55;
                cout<<ch;
            }
            else
                cout<<str2[k];
        }
    }
    
    
}
int main()
{
    cin>>m;
    IntTenToX(m,2);
    IntTenToX(m,8);
    IntTenToX(m,16);
    
    return 0;
}
