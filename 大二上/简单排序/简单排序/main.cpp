//
//  main.cpp
//  简单排序
//
//  Created by apple on 2017/12/14.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#define MAXSIZE 10
using namespace std;
typedef struct
{
    /* 用于存储要排序数组，r[0]用作哨兵或临时变量 */
    int r[MAXSIZE + 1];
    /* 用于记录顺序表的长度 */
    int length;
}SqList;
/* 交换L中数组r的下标为i和j的值 */
void swap(SqList *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

/* 对顺序表L作改进冒泡算法 */
void BubbleSort(SqList *L)
{
    int i, j;
    /* flag用来作为标记 */
    bool flag = 1;
    /* 若flag为true说明有过数据交换，否则停止循环 */
    for (i = 1; i < L->length && flag; i++)
    {
        /* 初始为false */
        flag = 0;
        for (j = L->length - 1; j >= i; j--)
        {
            if (L->r[j] > L->r[j + 1])
            {
                /* 交换L->r[j]与L->r[j+1]的值 */
                swap(L, j, j + 1);
                /* 如果有数据交换，则flag为true */
                flag = 1;
            }
        }
    }
}

/* 对顺序表L作简单选择排序 */
void SelectSort(SqList *L)
{
    int i, j, min;
    for (i = 1; i < L->length; i++)
    {
        /* 将当前下标定义为最小值下标 */
        min = i;
        /* 循环之后的数据 */
        for (j = i + 1; j <= L->length; j++)
        {
            /* 如果有小于当前最小值的关键字 */
            if (L->r[min] > L->r[j])
            /* 将此关键字的下标赋值给min */
                min = j;
        }
        /* 若min不等于i，说明找到最小值，交换 */
        if (i != min)
        {
            swap(L, i, min);
        }
        }
}

/* 对顺序表L作直接插入排序 */
void InsertSort(SqList *L)
{
    int i, j;
    for (i = 2; i <= L->length; i++)
    {
        /* 需将L->r[i]插入有序子表 */
        if (L->r[i] < L->r[i - 1])
        {
            /* 设置哨兵 */
            L->r[0] = L->r[i];
            for (j = i - 1; L->r[j] > L->r[0]; j--)
                /* 记录后移 */
                L->r[j + 1] = L->r[j];
            /* 插入到正确位置 */
            L->r[j + 1] = L->r[0];
        }
    }
}

/* 对顺序表L作二分插入排序 */
void BinaryInsertSort(SqList *L)
{
    int middle;
    for (int i=0; i < L->length; i++) {
        /* 带插入元素 */
        L->r[0] = L->r[i];
        int left = 0;
        int right = i - 1;
        /*  */
        while (left <= right) {
            middle = (left + right) /2;
            if (L->r[0] > L->r[middle]) {
                left = middle + 1;
            }
            else right = middle - 1;
        }
        for (int j=i; j > left; j--) {
            L->r[j] = L->r[j - 1];
        }
        L->r[left] = L->r[0];
    }
}
/* 对顺序表L作希尔排序 */
void ShellSort(SqList *L)
{
    int i, j;
    int increment = L->length;
    do
    {
        /* 增量序列 */
        increment = increment / 3 + 1;
        for (i = increment + 1; i <= L->length; i++)
        {
            if (L->r[i] < L->r[i - increment])
            {
                /* 需将L->r[i]插入有序增量子表 */
                /* 暂存在L->r[0] */
                L->r[0] = L->r[i];
                for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
                /* 记录后移，查找插入位置 */
                    L->r[j + increment] = L->r[j];
                /* 插入 */
                L->r[j + increment] = L->r[0];
            }
        }
    }
    while (increment > 1);
}




/* 已知L->r[s..m]中记录的关键字除L->r[s]之外
  均满足堆的定义 */
/* 本函数调整L->r[s]的关键字，使L->r[s..m]成
 为一个大顶堆 */
void HeapAdjust(SqList *L,int s,int m)
{
    int temp, j;
    temp = L->r[s];
    /* 沿关键字较大的孩子结点向下筛选 */
    for (j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && L->r[j] < L->r[j + 1])
        /* j为关键字中较大的记录的下标 */
            ++j;
        if (temp >= L->r[j])
        /* rc应插入在位置s上 */
            break;
        L->r[s] = L->r[j];
        s = j;
    }
    /* 插入 */
    L->r[s] = temp;
}
/* 对顺序表L进行堆排序 */
void HeapSort(SqList *L)
{
    int i;
    /* 把L中的r构建成一个大顶堆 */
    for (i = L->length / 2; i > 0; i--)
        HeapAdjust(L, i, L->length);
    for (i = L->length; i > 1; i--)
    {
        /* 将堆顶记录和当前未经排序子序列的最后一个记录交换 */
        swap(L, 1, i);
        /* 将L->r[1..i-1]重新调整为大顶堆 */
        HeapAdjust(L, 1, i - 1);
    }
}






/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的
 TR[i..n] */
void Merge(int SR[], int TR[], int i, int m, int n)
{
    int j, k, l;
    /* 将SR中记录由小到大归并入TR */
    for (j = m + 1, k = i; i <= m && j <= n; k++)
    {
        if (SR[i] < SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    if (i <= m)
    {
        for (l = 0; l <= m - i; l++)
        /* 将剩余的SR[i..m]复制到TR */
            TR[k + l]=SR[i + l];
    }
    if (j<=n)
    {
        for (l = 0; l <= n - j; l++)
        /* 将剩余的SR[j..n]复制到TR */
            TR[k + l] = SR[j + l];
    }
}
/* 将SR[s..t]归并排序为TR1[s..t] */
void MSort(int SR[], int TR1[], int s, int t)
{
    int m;
    int TR2[MAXSIZE + 1];
    if (s == t)
        TR1[s] = SR[s];
    else
    {
        /* 将SR[s..t]平分为SR[s..m]和SR[m+1..t] */
        m = (s + t) / 2;
        /* 递归将SR[s..m]归并为有序的TR2[s..m] */
        MSort(SR, TR2, s, m);
        /* 递归将SR[m+1..t]归并为有序TR2[m+1..t] */
        MSort(SR, TR2, m + 1, t);
        /* 将TR2[s..m]和TR2[m+1..t] */
        /* 归并到TR1[s..t] */
        Merge(TR2,TR1, s, m, t);
    }
}
/* 对顺序表L作归并排序 */
void MergeSort(SqList *L)
{
    MSort(L->r, L->r, 1, L->length);
}







/* 将SR[]中相邻长度为s的子序列两两归并到TR[] */
void MergePass(int SR[], int TR[], int s, int n)
{
    int i = 1;
    int j;
    while (i <= n - 2 * s + 1)
    {
        /* 两两归并 */
        Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
        i = i + 2 * s;
    }
    /* 归并最后两个序列 */
    if (i < n - s + 1)
        Merge(SR, TR, i, i + s - 1, n);
    /* 若最后只剩下单个子序列 */
    else
        for (j = i; j <= n; j++)
            TR[j] = SR[j];
}
/* 对顺序表L作归并非递归排序 */
void MergeSort2(SqList *L)
{
    /* 申请额外空间 */
    int * TR = (int *)malloc(L->length * sizeof(int));
    int k = 1;
    while (k < L->length)
    {
        MergePass(L->r, TR, k, L->length);
        /*子序列长度加倍 */
        k = 2 * k;
        MergePass(TR, L->r, k, L->length);
        /* 子序列长度加倍 */
        k = 2 * k;
    }
}







/* 交换顺序表L中子表的记录，使枢轴记录到位，
  并返回其所在位置 */
/* 此时在它之前（后）的记录均不大（小）于
 它。 */
int Partition(SqList *L, int low, int high)
{
    int pivotkey;
    /* 用子表的第一个记录作枢轴记录 */
     pivotkey = L->r[low];
    /* 从表的两端交替向中间扫描 */
    while (low < high)
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        /* 将比枢轴记录小的记录交换到低端 */
        swap(L, low, high);
        while (low < high && L->r[low] <= pivotkey)
            low++;
        /* 将比枢轴记录大的记录交换到高端 */
        swap(L, low, high);
    }
    /* 返回枢轴所在位置 */
    return low;
}
/* 对顺序表L中的子序列L->r[low..high]作快速排
  序 */
void QSort(SqList *L, int low, int high)
{
    int pivot;
    if (low < high)
    {
        /* 将L->r[low..high]一分为二， */
        /* 算出枢轴值pivot */
        pivot = Partition(L, low, high);
        /* 对低子表递归排序 */
        QSort(L, low, pivot - 1);
        /* 对高子表递归排序 */
        QSort(L, pivot + 1, high);
    }
}
/* 对顺序表L作快速排序 */
void QuickSort(SqList *L)
{
    QSort(L, 1, L->length);
}

int main(int argc, const char * argv[]) {
    SqList* list = new SqList;
    list->length = 10;
    for (int i = 1; i < 11; i++) {
        list->r[i] = 122 - i;
        
    }
    ShellSort(list);
    for (int i = 1; i < 11; i++) {
        cout << list->r[i]<<endl;
        
    }
    
    return 0;
}






