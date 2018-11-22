//
//  main.cpp
//  1083: 递增序列
//
//  Created by apple on 2016/12/8.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
using namespace std;
int A[10];
bool Is_ascend(int A[], int n)
{
    if(n==1)
        return 1;
    if (A[n-2]>=A[n-1]) {
        return 0;
    }
    else
    {
    n--;
    return Is_ascend(A,n);
    }
}
int main()
{
    for (int i=0; i<10; i++) {
        cin>>A[i];
    }
    for (int i=10; i>0; i--) {
        if (Is_ascend(A,i)) {
            cout<<i;
            break;
        }
    }
    return 0;
}
