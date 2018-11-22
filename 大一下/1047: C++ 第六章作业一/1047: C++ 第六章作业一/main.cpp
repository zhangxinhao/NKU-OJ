//
//  main.cpp
//  1047: C++ 第六章作业一
//
//  Created by apple on 2017/4/1.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char  str1[101];
    char  str2[101];
    int i,j,s1,s2,judge1=1,judge=0;
    
    cin>>str1>>str2;
    s2=strlen(str2);
    s1=strlen(str1);
    for (i=0; i<s1; i++)
    {
        if (str1[i]==str2[0])
        {
            for (j=1; j<s2; j++)
            {
                if (str1[i+j]!=str2[j])
                {
                    judge1=0;
                    break;
                }
            }
            if (judge1==1)
            {
                if (i==0)
                {
                    cout<<str1;
                    judge=1;
                    break;
                }
                else
                {
                    str1[i]='\0';
                    cout<<str1;
                    judge=1;
                    break;
                }
                
                
            }
            judge1=1;
        }
        
    }
    if (judge==0) {
        cout<<"Not found";
    }
    return 0;
}
