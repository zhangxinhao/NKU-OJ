//
//  main.cpp
//  1052: C++ 第七章作业二
//
//  Created by apple on 2017/4/17.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
using namespace std;
struct student
{
    int num;
    int grade;
    
};
int main(int argc, const char * argv[]) {
    student s[4];
    for (int i=0; i<4; i++) {
        cin>>s[i].num>>s[i].grade;
    }
    int max=s[0].grade;
    for (int i=1; i<4; i++) {
        if (max<s[i].grade) {
            max=s[i].grade;
        }
    }
    for (int i=0; i<4; i++) {
        if (s[i].grade==max) {
            cout<<s[i].num<<" "<<s[i].grade<<endl;
        }
    }
    
    return 0;
}
