//
//  main.cpp
//  最佳调度问题
//
//  Created by apple on 2018/4/17.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int n, k, ans;
int mymin(int * res, int k){
    int ls = 0;
    for (int i = 0; i < k; i++) {
        if (res[i] < res[ls]) {
            ls = i;
        }
    }
    return ls;
}
int mymax(int * res, int k){
    int ls = 0;
    for (int i = 0; i < k; i++) {
        if (res[i] > res[ls]) {
            ls = i;
        }
    }
    return ls;
}
void dfs(int x,int y,int * time,int* res){
    if (y >= ans) {
        return;
    }
    if (x == -1) {
        if (y < ans) {
            ans = y;
            return;
        }
    }
    for (int i = 0; i < k; i++) {
        if (res[i] + time[x] < ans) {
            res[i] += time[x];
            dfs(x - 1, max(y, res[i]), time, res);
            res[i] -= time[x];
        }
    }
    return;
}
int main(int argc, const char * argv[]) {
    cin >> n >> k;
    int* time = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    sort(time, time + n);
    int* res = new int[k];
    for (int i = n-1; i >= 0; i--) {
        res[mymin(res, k)] += time[i];
    }
    ans = res[mymax(res, k)];//greedy  min time
    for (int i = 0; i < k; i++) {
        res[i] = 0;
    }
    dfs(n-1, 0, time, res);
    cout << ans;
    return 0;
}

