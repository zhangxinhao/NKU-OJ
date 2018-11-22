//
//  main.cpp
//  最短路径
//
//  Created by apple on 2018/5/8.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#define inf __DBL_MAX__
using namespace std;

struct dot{
    double x;
    double y;
};

double Dijkstra(int n, int a, int b, double ** matrix){
    double *dist = new double[n+1];
    bool visited[n+1];
    memset(visited,0,sizeof(visited));
    visited[a] = true;
    for (int i = 1; i <= n; i++) {
        dist[i] = matrix[a][i];
    }
    double min;
    int index = 0;
    for (int i = 1; i < n; i++) {
        min = inf;
        index = 0;
        for (int j = 1; j <= n; j++) {
            if (visited[j] == 0 && dist[j] < min) {
                min = dist[j];
                index = j;
            }
        }
        visited[index] = true;
        if (visited[b]) {
            break;
        }
        for (int k = 1; k <= n; k++) {
            if (matrix[index][k] < inf && visited[k] == 0) {
                if (dist[k] > dist[index] + matrix[index][k]) {
                    dist[k] = dist[index] + matrix[index][k];
                }
            }
        }
        
    }
    return dist[b];
}
int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n;
    dot* point = new dot[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> point[i].x >> point[i].y;
    }
    
    double ** matrix = new double*[n+1];
    for (int i = 1; i <= n; i++) {
        matrix[i] = new double[n+1];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = inf;
        }
    }
    
    cin >> m;
    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        matrix[a][b] = matrix[b][a] = sqrt(pow((point[a].x-point[b].x), 2) + pow((point[a].y-point[b].y), 2));
    }
    cin >> a >> b;
    cout << fixed << setprecision(2) << Dijkstra(n, a, b, matrix) << endl;
    return 0;
}
