//
//  main.cpp
//  小镇改造
//
//  Created by apple on 2018/4/24.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int q;
    int w;
    int e;
};
void init(int n, int *pre){
    for (int i = 1; i <= n; i++) {
        pre[i] = i;
    }
}
int find(int x, int*pre){
    while (pre[x] != x) {
        x = pre[x];
    }
    return x;
}
void join(int x, int y, int *pre){
    int a = find(x, pre);
    int b = find(y, pre);
    if (a != b) {
        pre[a] = b;
    }
}
bool cmp(edge e1, edge e2){
    return e1.e < e2.e;
}
int kruskal(int n, int m, int *pre, edge* eg){
    int max = 0;
    init(n, pre);
    sort(eg, eg + m, cmp);
    for (int i = 0; i < m; i++) {
        if (find(eg[i].q, pre) != find(eg[i].w, pre)) {
            join(eg[i].q, eg[i].w, pre);
            if (max < eg[i].e) {
                max = eg[i].e;
            }
        }
        
    }
    return max;
}
int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    int * pre = new int[n + 1];
    edge* eg = new edge[m];
    for (int i = 0; i < m; i++) {
        cin >> eg[i].q >> eg[i].w >> eg[i].e;
    }
    cout << kruskal(n, m, pre, eg);
    return 0;
}







