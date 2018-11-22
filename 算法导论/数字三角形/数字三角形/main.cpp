//
//  main.cpp
//  数字三角形
//
//  Created by apple on 6/2/18.
//  Copyright © 2018 apple. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int D[MAX][MAX];
int n;
int * maxSum;

int main(int argc, const char * argv[]) {
    int i,j;
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            cin >> D[i][j];
        }
    }
    maxSum = D[n];
    for (int i = n-1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            maxSum[j] = max(maxSum[j],maxSum[j + 1])+D[i][j];
        }
    }
    cout << maxSum[1];
    return 0;
}
