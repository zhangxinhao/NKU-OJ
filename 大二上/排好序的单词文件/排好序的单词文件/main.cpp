//
//  main.cpp
//  排好序的单词文件
//
//  Created by apple on 2017/11/16.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
#define MAX   17853
ofstream output("/Users/apple/Documents/orderoutput");
fstream input("/Users/apple/Documents/2hash.txt");
int main(int argc, const char * argv[]) {
    multimap<int,string> wmap;
    map<string,int> m;
    string str;
    int c;
    unsigned int sum;
    for (int i = 0; i < MAX; i++) {
        input >> str >> c;
        m[str] = c;
        sum += str.size() * 8 * c;
    }
    cout<< sum <<endl;
    
    return 0;
}
