//
//  main.cpp
//  hash2
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
#define NHASH 30817
ofstream output("/Users/apple/Documents/hash2.txt");
string arr[NHASH];
int _count[NHASH];
int clash = 0;
unsigned int _hash(const char *p)
{
    unsigned int h = 0;
    for(; *p; p++)
        h = (h << 5) + *p;
    return h % NHASH;
}
unsigned int _hash2(const char *p)
{
    unsigned int h = 0,i= 0;
    while (p[i]) {
        h += p[i];
        i++;
    }
    return h % NHASH;
}

void insert(const char *s)
{
    int i = _hash2(s);
    while (arr[i] != "") {
        if(strcmp(s,arr[i].data()) == 0){
            _count[i]++;
            return;
        }else if (i != _hash2(arr[i].data())){
            clash++;
            i = (i+1)%NHASH;
        }else{
            i = (i+1)%NHASH;
            
        }
        
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
    for( i=0; i<NHASH; i++){
        if (arr[i] != "") {
            output.setf(ios::left);
            output << setw(25)<< arr[i] << _count[i] << endl;
        }
        
        
    }
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    cout<<clash<<endl;
    return 0;
}
