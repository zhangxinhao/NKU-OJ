//
//  main.cpp
//  最小生成树：室内布线
//
//  Created by apple on 2017/12/21.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
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



int main()
{
    int N,len,wid,hei,pos_door;

    
    // i,j 为中间变量，k为边的个数
    int i,j,k;
    while(  )
    {
        // 输入数据为4个0，则退出程序
        if( !len && !wid && !hei && !N )    break;
        
        // 获取数据（插座与门的位置）
        for( i=0 ; i<N ; ++i )
            cin>>nd[i].x>>nd[i].y>>nd[i].z;
        for( i=0 ; i<4 ; ++i )
            cin>>door[i].x>>door[i].y>>door[i].z;
        pos_door=judge_d( door );
        
        /* 求两点间距离（注意，布线要与墙平行） */
        k=0;
        for( i=0 ; i<N ; ++i )
        {
            for( j=i+1; j<N ; ++j )
            {
                eg[k].u=i;
                eg[k].v=j;
                // 判断两点关系，同墙or相邻墙or相对墙
                
                // 同墙
                if( isTogether( nd[i] , nd[j] ) )   eg[k].quan=find_togcost(nd[i],nd[j]);
                // 相对墙
                else if( isAcross( nd[i] , nd[j] ) )    eg[k].quan=find_acrcost(nd[i],nd[j]);
                // 相邻墙
                else    eg[k].quan=find_bescost(nd[i],nd[j]);
                ++k;
            }
        }
        
        /* 用Kruscal算法求最小生成树 */
        // 注意最后，无论长度如何，都要向上取整
        double cost;
        cost=Kruskal(k);
        if( cost-int(cost)==0 ) cout<<cost<<endl;
        else    cout<<int(cost+1)<<endl;
    }
}



/******  一些相关变量的定义 ******/

// 插座个数，最多为20个，所以，边最多只有400个
#define MAX 401
// 点的结构体
struct node
{
    double x,y,z;
}nd[21],door[4];
// 含权值的边的结构体
struct edge
{
    int u;
    int v;
    double weight;
}eg[MAX];
// N - 插座个数，len,wid,hei - 房间的长、宽、高，pos_door门所在位置
int N,len,wid,hei,pos_door;
int father[21];



/******  判断两插座位置关系  ******/

// 是否在同一墙面
bool isTogether( node a , node b )
{
    if( (a.x==b.x && (a.x==0||a.x==len) ) || (a.y==b.y && (a.y==0||a.y==wid) ) )    return true;
    return false;
}
// 判断是否在相邻墙面
bool isBeside( node a , node b )
{
    if( a.x==0 || a.x==len )
    {
        if( b.y==0 || b.y==wid )
            return true;
        else
            return false;
    }
    else if( a.y==0 || a.y==wid )
    {
        if( b.x==0 || b.x==len )
            return true;
        else
            return false;
    }
    return 0;
}
// 是否在相对墙面
bool isAcross( node a , node b )
{
    if( (a.x==0 && b.x==len) || (a.y==0 && b.y==wid) || (a.x==len && b.x==0) || (a.y==wid && b.y==0) )
        return true;
    else
        return false;
}



/******  一系列判断  ******/

// 求最小值
double Min( double a,double b)
{
    return a<b?a:b;
}
// 判断门在哪个墙面
int judge_d( node d[] )
{
    if( d[0].y==0 && d[3].y==0 )    return 1;
    else if( d[0].x==0 && d[3].x==0 )   return 2;
    else if( d[0].x==len && d[3].x==len )   return 3;
    else if( d[0].y==wid && d[3].y==wid )   return 4;
    return 0;
}
// 判断两个同墙插座间连线是否穿门
bool judge_crossdoor( node n1, node n2 )
{
    // 如果插座在最下面，或者插座位置高于门的位置，则不穿过门（无论墙和插座位置关系如何）
    if( n1.z==0 || n2.z==0 || n1.z>=door[3].z || n2.z>=door[3].z )    return false;
    if( pos_door==1 )
    {
        if( n1.y!=0 && n2.y!=0 )    return false;
        if( (n1.x>=door[3].x && n2.x>=door[3].x) || (n1.x<=door[0].x && n2.x<=door[0].x) )  return false;
        return true;
    }
    else if( pos_door==2 )
    {
        if( n1.x!=0 && n2.x!=0 )    return false;
        if( (n1.y<=door[0].y && n2.y<=door[0].y) || (n1.y>=door[3].y && n2.y>=door[3].y) )  return false;
        return true;
    }
    else if( pos_door==3 )
    {
        if( n1.x!=len && n2.y!=len )    return false;
        if( (n1.y<=door[0].y && n2.y<=door[0].y) || (n1.y>=door[3].y && n2.y>=door[3].y) )  return false;
        return true;
    }
    else
    {
        if( n1.y!=wid && n2.y!=wid )    return false;
        if( (n1.x>=door[3].x && n2.x>=door[3].x) || (n1.x<=door[0].x && n2.x<=door[0].x) )  return false;
        return true;
    }
}



/******  求布线长度  ******/

// 求同墙两插座最短布线
double find_togcost( node a,node b )
{
    
    // 两插座同墙且不穿门
    if( !judge_crossdoor( a , b ) )
        return (fabs(a.x-b.x)+fabs(a.y-b.y)+fabs(a.z-b.z));
    else
    {
        // 两插座布线会穿过门，门的位置不同
        if( pos_door==1 || pos_door==4 )    return Min( (fabs(a.x-b.x)+fabs(door[3].z-a.z)+fabs(door[3].z-b.z) ),(fabs(a.x-b.x)+a.z+b.z) );
        else    return  Min( (fabs(a.y-b.y)+fabs(door[3].z-a.z)+fabs(door[3].z-b.z)),(fabs(a.y-b.y)+a.z+b.z) );
    }
}
// 求相对墙两插座最短布线
double find_acrcost( node a,node b )
{
    double cost1,cost2;
    node temp1,temp2;
    // 插座在1,4面
    if( (a.y==0 && b.y==wid) || (b.y==0 && a.y==wid) )
    {
        // 根据门的位置，求权值
        if( pos_door==1 )   return  Min( Min( (a.y+fabs(door[3].z-a.z)+len+b.y),(a.y+a.z+len+b.y) ),Min( (wid-a.y+len+wid-b.y),(a.z+len+b.z) ) );
        else if( pos_door==2 )
        {
            temp1=temp2=a;
            temp1.y=0,temp2.y=wid;
            cost1=find_togcost(a,temp1);
            cost2=find_togcost(a,temp2);
            return  Min( (cost1+len+b.y),(cost2+len+wid-b.y) );
        }
        else if( pos_door==3 )
        {
            temp1=temp2=b;
            temp1.y=0,temp2.y=wid;
            cost1=find_togcost(b,temp1);
            cost2=find_togcost(b,temp2);
            return  Min( (cost1+len+a.y),(cost2+len+wid-a.y) );
        }
        else    return  Min( Min( (a.y+len+b.y),(wid-a.y+wid-b.y+fabs(door[3].z-a.z)+len) ), Min( (wid-a.y+wid-b.y+a.z+len),(a.z+b.z+len) ) );
        
    }
    else
    {
        if( pos_door==1 )
        {
            temp1=temp2=a;
            temp1.x=0,temp2.x=len;
            cost1=find_togcost(a,temp1);
            cost2=find_togcost(a,temp2);
            return  Min( (cost1+wid+b.x),(cost2+wid+len-b.x) );
        }
        else if( pos_door==2 )  return Min( Min( (a.x+b.x+wid+fabs(door[3].z-a.z)),(a.x+b.x+wid+a.z) ),Min( (len-a.x+len-b.x+wid),(a.z+b.z+wid) ) );
        else if( pos_door==4 )
        {
            temp1=temp2=b;
            temp1.x=0,temp2.x=len;
            cost1=find_togcost(b,temp1);
            cost2=find_togcost(b,temp2);
            return Min( (cost1+wid+a.x),(cost2+wid+len-a.x) );
        }
        else return Min( Min( (a.x+b.x+wid),(a.z+b.z+wid) ),Min( (len-a.x+len-b.x+fabs(door[3].z-a.z)+wid),(len-a.x+len-b.x+a.z+wid) ) );
    }
}
// 求相邻墙两插座最短布线
double find_bescost( node a , node b )
{
    node temp=a;
    // 在两平面连接处找一个点（让其中一点x,y为0即可），转化为两个 同墙插座 问题
    if( (a.x==0 && b.y==0) || (b.x==0 && a.y==0) )
    {
        temp.x=temp.y=0;
        return ( find_togcost(a,temp)+find_togcost(b,temp) );
    }
    else if( (a.x==len && b.y==0) || (a.y==0 && b.x==len) )
    {
        temp.x=len,temp.y=0;
        return ( find_togcost(a,temp)+find_togcost(b,temp) );
    }
    else if( (a.x==0 && b.y==wid) || (b.x==0 && a.y==wid) )
    {
        temp.x=0,temp.y=wid;
        return ( find_togcost(a,temp)+find_togcost(b,temp) );
    }
    else
    {
        temp.x=len,temp.y=wid;
        return ( find_togcost(a,temp)+find_togcost(b,temp) );
    }
}



/******  求最小生成树(Kruscal)  ******/

// 比较函数
bool cmp(edge e1,edge e2)
{
    return e1.weight<e2.weight;
}
// 并查集 初始化函数
void Init( int m )
{
    int i;
    for(i=1;i<=m;i++)
        father[i]=i;
}
// 并查集 查找函数
int Find(int x)
{
    while(father[x]!=x)
        x=father[x];
    return x;
}
// 并查集 合并函数
void Combine(int a,int b)
{
    int temp_a,temp_b;
    temp_a=Find(a);
    temp_b=Find(b);
    
    if(temp_a!=temp_b)
        father[temp_a]=temp_b;
}
// 最小生成树 Kruskal 算法
double Kruskal( int n )
{
    edge e;
    int i;
    double res;
    sort(eg,eg+n,cmp);
    // 并查集 初始化
    Init(N);
    
    // 构建最小生成树
    res=0;
    for( i=0;i<n;++i )
    {
        e=eg[i];
        if( Find(e.u)!=Find(e.v) )
        {
            Combine(e.u,e.v);
            res+=e.weight;
        }
    }
    return res;
}



/****** 主函数 ******/

int main()
{
    // i,j 为中间变量，k为边的个数
    int i,j,k;
    while( cin>>len>>wid>>hei>>N )
    {
        // 输入数据为4个0，则退出程序
        if( !len && !wid && !hei && !N )    break;
        
        // 获取数据（插座与门的位置）
        for( i=0 ; i<N ; ++i )
            cin>>nd[i].x>>nd[i].y>>nd[i].z;
        for( i=0 ; i<4 ; ++i )
            cin>>door[i].x>>door[i].y>>door[i].z;
        pos_door=judge_d( door );
        
        /* 求两点间距离（注意，布线要与墙平行） */
        k=0;
        for( i=0 ; i<N ; ++i )
        {
            for( j=i+1; j<N ; ++j )
            {
                eg[k].u=i;
                eg[k].v=j;
                // 判断两点关系，同墙or相邻墙or相对墙
                
                // 同墙
                if( isTogether( nd[i] , nd[j] ) )   eg[k].quan=find_togcost(nd[i],nd[j]);
                // 相对墙
                else if( isAcross( nd[i] , nd[j] ) )    eg[k].quan=find_acrcost(nd[i],nd[j]);
                // 相邻墙
                else    eg[k].quan=find_bescost(nd[i],nd[j]);
                ++k;
            }
        }
        
        /* 用Kruscal算法求最小生成树 */
        // 注意最后，无论长度如何，都要向上取整
        double cost;
        cost=Kruskal(k);
        if( cost-int(cost)==0 ) cout<<cost<<endl;
        else    cout<<int(cost+1)<<endl;
    }
}
