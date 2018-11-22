//
//  main.cpp
//  随机数文件
//
//  Created by apple on 2017/12/7.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    ofstream output("/Users/apple/Documents/inorder.txt");
    for (int i = 0; i < 100000; i++) {
        output << i << endl;
    }
    return 0;
}
