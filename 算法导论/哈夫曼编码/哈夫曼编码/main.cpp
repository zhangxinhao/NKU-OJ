//
//  main.cpp
//  哈夫曼编码
//
//  Created by apple on 2018/5/22.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//Huffman 树的结构
typedef struct
{
    //字符
    char ch;
    //叶子结点权值
    unsigned int weight;
    //指向双亲，和孩子结点的指针
    unsigned int parent;
    unsigned int lChild;
    unsigned int rChild;
} Node, *HuffmanTree;

//存储哈夫曼编码
typedef char *HuffmanCode;

//选择两个parent为0，且weight最小的结点s1和s2
//n 为叶子结点的总数，s1和 s2两个指针参数指向要选取出来的两个权值最小的结点
void select(HuffmanTree *huffmanTree, int n, int *s1, int *s2)
{
    int i = 0;
    int min = 0;
    //遍历全部结点，找出单节点
    for(i = 1; i <= n; i++)
    {
        //如果此结点的父亲没有，那么把结点号赋值给 min，跳出循环
        if((*huffmanTree)[i].parent == 0)
        {
            min = i;
            break;
        }
    }
    //继续遍历全部结点，找出权值最小的单节点
    for(i = 1; i <= n; i++)
    {
        //如果此结点的父亲为空，则进入 if
        if((*huffmanTree)[i].parent == 0)
        {
            //如果此结点的权值比 min 结点的权值小，那么更新 min 结点，否则就是最开始的 min
            if((*huffmanTree)[i].weight < (*huffmanTree)[min].weight)
            {
                min = i;
            }
        }
    }
    //找到了最小权值的结点，s1指向
    *s1 = min;
    //遍历全部结点
    for(i = 1; i <= n; i++)
    {
        //找出下一个单节点，且没有被 s1指向，那么i 赋值给 min，跳出循环
        if((*huffmanTree)[i].parent == 0 && i != (*s1))
        {
            min = i;
            break;
        }
    }
    //继续遍历全部结点，找到权值最小的那一个
    for(i = 1; i <= n; i++)
    {
        if((*huffmanTree)[i].parent == 0 && i != (*s1))
        {
            //如果此结点的权值比 min 结点的权值小，那么更新 min 结点，否则就是最开始的 min
            if((*huffmanTree)[i].weight < (*huffmanTree)[min].weight)
            {
                min = i;
            }
        }
    }
    //s2指针指向第二个权值最小的叶子结点
    *s2 = min;
}

//创建哈夫曼树并求哈夫曼编码
void createHuffmanTree(HuffmanTree *huffmanTree, int n)
{
    int m = 2 * n - 1;
    int s1;
    int s2;
    int i;
    //动态内存分配
    *huffmanTree = new Node[m + 1];
    //1--n号存放叶子结点，初始化叶子结点，结构数组来初始化每个叶子结点
    for(i = 1; i <= n; i++)
    {
        cin >> (*huffmanTree)[i].ch;
        cin >> (*huffmanTree)[i].weight;
        (*huffmanTree)[i].lChild = 0;
        (*huffmanTree)[i].parent = 0;
        (*huffmanTree)[i].rChild = 0;
    }
    //非叶子结点的初始化
    for(i = n + 1; i <= m; i++)
    {
        (*huffmanTree)[i].ch = '\0';
        (*huffmanTree)[i].weight = 0;
        (*huffmanTree)[i].lChild = 0;
        (*huffmanTree)[i].parent = 0;
        (*huffmanTree)[i].rChild = 0;
    }
    //创建非叶子结点，构建哈夫曼树
    for(i = n + 1; i <= m; i++)
    {
        //在(*huffmanTree)[1]~(*huffmanTree)[i-1]的范围内选择两个parent为0
        //且weight最小的结点，其序号分别赋值给s1、s2
        select(huffmanTree, i-1, &s1, &s2);
        //选出的两个权值最小的叶子结点，组成一个新的二叉树，根为 i 结点
        (*huffmanTree)[s1].parent = i;
        (*huffmanTree)[s2].parent = i;
        (*huffmanTree)[i].lChild = s1;
        (*huffmanTree)[i].rChild = s2;
        //新的结点 i 的权值
        (*huffmanTree)[i].weight = (*huffmanTree)[s1].weight + (*huffmanTree)[s2].weight;
    }
}

//从 n 个叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码
void creatHuffmanCode(HuffmanTree *huffmanTree, HuffmanCode *huffmanCode, int n)
{
    int i;
    int start;
    int p;
    unsigned int c;
    huffmanCode = new HuffmanCode[n+1];
    char *cd = new char[n];
    cd[n-1] = '\0';
    //求n个叶子结点对应的哈夫曼编码
    for(i = 1; i <= n; i++)
    {
        //初始化编码起始指针
        start = n - 1;
        //从叶子到根结点求编码
        for(c = i, p = (*huffmanTree)[i].parent; p != 0; c = p, p = (*huffmanTree)[p].parent)
        {
            if( (*huffmanTree)[p].lChild == c)
            {
                //从右到左的顺序编码入数组内
                cd[--start] = '0';  //左分支标0
            }
            else
            {
                cd[--start] = '1';  //右分支标1
            }
        }
        huffmanCode[i] = new char[n - start];
        strcpy(huffmanCode[i], &cd[start]);
    }
    delete[] cd;
    int result = 0;
    //输出结果
    for(i = 1; i <= n; i++)
    {
        result += (*huffmanTree)[i].weight * strlen(huffmanCode[i]);
    }
    cout << result;
}


int main(void)
{
    HuffmanTree HT;
    HuffmanCode HC;
    int n;
    cin >> n;
    //构建Huffman树
    createHuffmanTree(&HT, n);
    //求Huffman编码
    creatHuffmanCode(&HT,&HC,n);
    return 0;
}




