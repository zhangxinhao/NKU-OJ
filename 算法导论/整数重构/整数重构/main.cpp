//
//  main.cpp
//  整数重构
//
//  Created by apple on 2018/5/21.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <iostream>
using namespace std;
string reconfig(string str, int n){
    static string result = "";
    int len  = str.length();
    int index = 0;
    for (int i = len - n ; i > 0; i--) {
        for (int j = index; j <= len - i; j++) {
            if (str[j] > str[index]) {
                index = j;
            }
        }
        result += str[index];
        index++;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    string str;
    cin >> str;
    int n;
    cin >> n;
    cout << reconfig(str, n);
    return 0;
}
