//
//  main.cpp
//  光盘刻录问题
//
//  Created by apple on 2018/4/3.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int n, x, total = 0;
struct node{
    int num;
    node * next;
};
void BFS(node * map, int i, int * visit){
    visit[i] = 1;
    queue<int> q;
    q.push(i);
    node * temp = NULL;
    while (!q.empty()) {
        temp = &map[q.front()];
        while (temp) {
            if (visit[temp->num] == 0) {
                visit[temp->num] = 1;
                q.push(temp->num);
            }
            temp = temp->next;
        }
        q.pop();
    }
    total++;
    return;
}
int main(int argc, const char * argv[]) {
    cin >> n;
    node * map = new node[n + 1];
    for (int i = 1; i <= n; i++) {
        map[i].num = i;
        map[i].next = NULL;
    }
    int * sum = new int[n + 1]{0};
    int * visit = new int[n + 1]{0};
    node * temp;
    for (int i = 1; i <= n; i++) {
        temp = &map[i];
        while (cin >> x) {
            if (x == 0) {
                temp->next = NULL;
                break;
            }else{
                temp->next = new node;
                temp->next->num = x;
                temp->next->next = NULL;
                temp = temp->next;
                sum[x]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (sum[i] == 0) {
            BFS(map, i, visit);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) {
            BFS(map, i, visit);
        }
    }
    cout << total;
    
    
    return 0;
}
