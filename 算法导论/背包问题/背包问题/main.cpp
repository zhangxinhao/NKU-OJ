//
//  main.cpp
//  背包问题
//
//  Created by apple on 6/8/18.
//  Copyright © 2018 apple. All rights reserved.
//

#include <iostream>
using namespace std;
int c,n;
int *w,*v,*flag;
int main(int argc, const char * argv[]) {
    
    cin >> c >> n;
    int weignt = c;
    w = new int[n+1];
    v = new int[n+1];
    flag = new int[n+1];
    int ** result = new int *[n+1];
    for (int i = 1; i <= n; i++) {
        result[i] = new int[c+1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        flag[i] = 0;
    }
    for (int i = 1; i <= c; i++) {
        if (i >= w[1]) {
            result[1][i] = v[1];
        }else{
            result[1][i] = 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (j >= w[i]) {
                result[i][j] = max(result[i - 1][j],result[i - 1][j - w[i]] + v[i]);
            }else{
                result[i][j] = result[i - 1][j];
            }
        }
    }
    for (int i = n; i > 1 ; i--) {
        if (result[i][c] == result[i-1][c]) {
            flag[i] = 0;
        }else{
            flag[i] = 1;
            c -= w[i];
        }
    }
    flag[1] = (c > w[1])?1:0;
    for (int i = 1; i <= n; i++) {
        cout << flag[i];
    }
    cout << endl;
    cout << result[n][weignt];
    
    return 0;
}
