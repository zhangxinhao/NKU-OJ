//
//  main.cpp
//  1048: C++ 第六章作业二
//
//  Created by apple on 2017/4/1.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main() {
    int n,i,j,now;
    cin>>n;
    string p[100];
    string pn;
    for (i=0; i<n; i++) {
        p[i]=*new string;
    }
    for (i=0; i<n; i++) {
        cin>>p[i];
    }
    for (i=0; i<n; i++) {
        pn=p[0];
        now=0;
        for (j=0; j<n-1; j++) {
            if (p[j+1]<=pn) {
                pn=p[j+1];
                now=j+1;
                p[j+1][0]='|'+10;
            }
        }
        cout<<now+1<<" ";
        
    }
    
    return 0;
}


//bool judge(string str1,string str2)
//{
//    int s1,s2;
//    s1=str1.size();
//    s2=str2.size();
//    int i=0;
//    for (i=0; i<s1 && i<s2; i++) {
//        if (str1[i]<str2[i]) {
//            return 1;
//        }
//        if (str1[i]>str2[i]) {
//            return 0;
//        }
//    }
//    if(s1<s2)
//        return 1;
//    else
//        return 0;
//    
//}

