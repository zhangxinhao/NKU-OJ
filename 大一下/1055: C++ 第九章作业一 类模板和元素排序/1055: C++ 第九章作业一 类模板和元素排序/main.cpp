//
//  main.cpp
//  1055: C++ 第九章作业一 类模板和元素排序
//
//  Created by apple on 2017/5/14.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
template <typename T>
class sortt {
public:
    int n;
    T * arr;
    sortt(int n)
    {
        this->n = n;
        
    }
    void init()
    {
        arr = new T[n];
    }
    void print()
    {
        sort(&arr[0], &arr[n-1]+1);
        for (int i=0; i<n; i++) {
            cout<<arr[i];
            if (i<n-1) {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
};
int main() {
    int n;
    cin>>n;
    sortt<int> a(n);
    a.init();
    for (int i=0; i<n; i++) {
        cin>>a.arr[i];
    }
    a.print();

    cin>>n;
    sortt<char> b(n);
    b.init();
    for (int i=0; i<n; i++) {
        cin>>b.arr[i];
    }
    b.print();
    
    cin>>n;
    sortt<string> c(n);
    c.init();
    for (int i=0; i<n; i++) {
        cin>>c.arr[i];
    }
    c.print();
    return 0;
}
