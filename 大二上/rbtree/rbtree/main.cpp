//
//  main.cpp
//  rbtree
//
//  Created by apple on 2017/12/28.
//  Copyright © 2017年 apple. All rights reserved.
//

/**
 * C++ ”Ô—‘: ∂˛≤Ê≤È’“ ˜
 *
 * @author skywang
 * @date 2013/11/07
 */

#include <iostream>
#include<fstream>
#include<time.h>
#include "rbt.hpp"
using namespace std;

int main()
{
    
    int a[100000];
    fstream input("/Users/apple/Documents/random.txt");
    //ifstream fin1("data1.txt");
    //ifstream input("data2.txt");
    clock_t start_time, end_time;
    RBTree<int>* tree = new RBTree<int>();
    
    for (int i = 0; i < 100000; i++)
        a[i] = i;
    for (int i =1000; i<=100000; i+=3000)
    {
        start_time = clock();
        for (int j = 0; j < i; j++)
        {
            tree->insert(a[j]);
            
        }
        for (int j = 0; j < i; j++)
        {
            tree->remove(a[j]);
        }
        end_time = clock();
        //cout << i << " ";
        cout << double(end_time - start_time) / CLOCKS_PER_SEC << endl;
    }
    cout << endl;
    
    for (int i = 1000; i <= 100000; i += 3000)
    {
        start_time = clock();
        for (int j = 0; j < i; j++)
        {
            tree->insert(a[j]);
            
        }
        for (int j = 0; j < i; j++)
        {
            tree->remove(a[i - j - 1]);
        }
        end_time = clock();
        //cout << i << " ";
        cout << double(end_time - start_time) / CLOCKS_PER_SEC << endl;
    }
    cout << endl;
    
    for (int i = 0; i < 100000; i++)
        input >> a[i];
    for (int i = 1000; i <= 100000; i += 3000)
    {
        start_time = clock();
        for (int j = 0; j < i; j++)
        {
            tree->insert(a[j]);
            
        }
        for (int j = 0; j < i; j++)
        {
            tree->remove(a[j]);
        }
        end_time = clock();
        //cout << i << " ";
        cout << double(end_time - start_time) / CLOCKS_PER_SEC << endl;
    }
    tree->destroy();
    return 0;
}
