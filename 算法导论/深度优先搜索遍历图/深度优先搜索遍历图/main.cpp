//
//  main.cpp
//  深度优先搜索遍历图
//
//  Created by apple on 2018/3/27.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <iostream>
using namespace std;
int visit[101],sum,n,e[101][101];
void dfs(int cur){
    int i;
    sum++;
    if(sum==n) return;
    for(i=1;i<=n;i++)
    {
        if(e[cur][i]==1 && visit[i]==0)
        {
            visit[i]=1;
            cout << i <<" ";
            dfs(i);
        }
    }
    return;
}

int main()
{
    sum = 0;
    int i,j,m,v;
    cin >> n >> v;
    for(i=1;i<=n;i++)
    {
        for (j = 1; j <= n; j++) {
            cin >> m;
            if (i <= j) {
                e[i][j] = m;
                e[j][i] = m;
            }
            
        }
    }
    visit[v]=1;
    cout << v <<" ";
    dfs(v);
    while (sum < n) {
        for (i = 1; i <= n; i++) {
            if (visit[i] == 0) {
                visit[i] = 1;
                cout << i << " ";
                dfs(i);
            }
        }
    }
    return 0;
}
