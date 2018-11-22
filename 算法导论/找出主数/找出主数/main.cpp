//
//  main.cpp
//  找出主数
//
//  Created by apple on 2018/3/20.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int s[10] = {0};
    int n = 0, a;
    while (cin>>a) {
        n++;
        s[a]++;
    }
    int j = n/2;
    //cout << n << j << endl;
    for (int i = 0; i < 10; i++) {
        if (s[i] > j) {
            cout << i;
            n = 0;
            break;
        }
    }
    if (n != 0) {
        cout<< -1;
    }
    return 0;
}
