//
//  main.cpp
//  文件io练习
//
//  Created by apple on 2017/4/17.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;
int judge(int k)
{
    if (k<=1) {
        return 0;
    }
    if (k==2) {
        return 1;
    }
    for (int i=2; i<k; i++) {
        if (k%i==0) {
            return 0;
        }
        
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    int k;
    cin>>k;
    if (!judge(k)) {
        return 0;
    }
    set<int> s;
    s.insert(k);
    cin>>k;
    while (judge(k)) {
        s.insert(k);
        cin>>k;
    }
    set<int>::iterator it=s.begin();
    while (it!=s.end()) {
        cout<<*it++<<" ";
    }
    return 0;
    
}
