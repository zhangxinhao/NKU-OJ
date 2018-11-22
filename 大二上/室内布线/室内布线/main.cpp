//
//  main.cpp
//  室内布线
//
//  Created by apple on 2017/12/21.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N,length,width,height;
struct node
{
    double x,y,z;
};
struct edge
{
    int u;
    int v;
    double weight;
};
//判断对墙
bool is_across( node a , node b )
{
    if( (fabs(a.y-b.y) == width) || (fabs(a.x-b.x) == length) )
        return true;
    else
        return false;
}
//求最短路径
double path( node a,node b )
{
    if (is_across( a, b )) {
        if( fabs(a.y-b.y) == width )
        {
            double cost,arr[6],min;
            cost = fabs(a.x-b.x) + fabs(a.z-b.z) + width;
            arr[0] = a.x - 0;arr[1] = length - a.x;arr[2] = a.z;
            arr[3] = b.x - 0;arr[4] = length - b.x;arr[5] = b.z;
            min = arr[0];
            for (int i = 1; i < 6; ++i) {
                if (arr[i] < min) {
                    min = arr[i];
                }
            }
            cost += min * 2;
            return cost;
        }
        else
        {
            double cost,arr[6],min;
            cost = fabs(a.y-b.y) + fabs(a.z-b.z) + length;
            arr[0] = a.y - 0;arr[1] = width - a.y;arr[2] = a.z;
            arr[3] = b.y - 0;arr[4] = width - b.y;arr[5] = b.z;
            min = arr[0];
            for (int i = 1; i < 6; ++i) {
                if (arr[i] < min) {
                    min = arr[i];
                }
            }
            cost += min * 2;
            return cost;
        }
    }
    else
    {
        return (fabs(a.x-b.x)+fabs(a.y-b.y)+fabs(a.z-b.z));
    }
}
bool cmp(edge e1,edge e2)
{
    return e1.weight<e2.weight;
}
//最小生成树 Kruskal 算法
double Kruskal( int n ,edge *eg)
{
    int i;
    double sum = 0;
    int sn1,sn2,k,j;
    sort(eg,eg+n,cmp);
    int vset[N+1];
    for (i=0;i <= N;i++)
    {
        vset[i]=i;
    }
    // 构建最小生成树
    k = 1;
    j = 0;
    while (k <= N)
    {
        sn1=vset[eg[j].u];
        sn2=vset[eg[j].v];
        if (sn1!=sn2)
        {
            k++;
            for (i = 0;i <= N;i++)
            {
                if (vset[i]==sn2)
                {
                    vset[i]=sn1;
                }
            }
            sum+=eg[j].weight;
        }
        j++;
    }
    
    return sum;
}

int main(int argc, const char * argv[]) {
    
    // 输入长宽高N
    cin>>length>>width>>height>>N;
    // 获取数据
    node *nd = new node[N+1];
    nd[0].x = nd[0].y = nd[0].z = 0;
    for( int i = 1 ; i <= N ; ++i )
        cin>>nd[i].x>>nd[i].y>>nd[i].z;
    // 求路长
    int k = 0;
    edge *eg = new edge[(N+1)*N/2];
    for (int i = 0; i <= N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            eg[k].u = i;
            eg[k].v = j;
            eg[k].weight = path(nd[i], nd[j]);
            ++k;
        }
    }
    double cost;
    cost=Kruskal( k , eg );
    if( cost-int(cost)==0 )
        cout<<cost<<endl;
    else
        cout<<int(cost+1)<<endl;
    return 0;
}
