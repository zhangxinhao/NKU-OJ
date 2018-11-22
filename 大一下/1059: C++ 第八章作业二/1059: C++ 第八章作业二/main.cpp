//
//  main.cpp
//  1059: C++ 第八章作业二
//
//  Created by apple on 2017/4/24.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int Abs(int a,int b)
{
    if (a>=b) {
        return a-b;
    }
    else
        return b-a;
}
int main(int argc, const char * argv[]) {
    int x1,y1,x2,y2;
    int dis1,dis2;
    cin>>x1>>y1>>x2>>y2;
    dis1=Abs(x1,x2)+Abs(y1,y2);
    dis2=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    cout<<dis1<<" "<<dis2;
    return 0;
}
