//
//  main.cpp
//  统计词频_array
//
//  Created by apple on 2017/11/2.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <ctime>
using namespace std;
#define NHASH 20000
ofstream output("/Users/apple/Documents/array.txt");
string arr[NHASH];
int _count[NHASH];

void insert(const char *s)
{
    int i = 0;
    while (arr[i] != "") {
        if(strcmp(s,arr[i].data()) == 0){
            _count[i]++;
            return;
        }
        i++;
    }
    arr[i] = s;
    _count[i] = 1;
}

int main(int argc, const char * argv[]) {
    
    clock_t start, end;
    start = clock();
    
    fstream input("/Users/apple/Documents/input.txt");
    string  temp;
    char ch;
    input.get(ch);
    temp.clear();
    
    while (!input.eof())
    {
        if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z') || ch == '\'' || ch == '-')
        {
            if (ch >= 'A'&&ch <= 'Z')
                ch += 32;
            temp += ch;
        }
        else
            if (temp != "")
            {
                insert(temp.c_str());
                temp.clear();
            }
        input.get(ch);
    }
    int i = 0;
    for( i=0; arr[i] != ""; i++){
        output.setf(ios::left);
        output << setw(25)<< arr[i] << _count[i] << endl;
        
    }
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    cout<<i<<endl;
    return 0;
}
