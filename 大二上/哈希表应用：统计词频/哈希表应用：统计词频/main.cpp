//
//  main.cpp
//  哈希表应用：统计词频
//
//  Created by apple on 2017/10/27.
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

void insert(const char *s)
{
    int i = _hash(s);
    
    
    int num = 0;
    
    while (arr[i] != "") {
        if(strcmp(s,arr[i].data()) == 0){
            _count[i]++;
            return;
        }
        else if (i != _hash(arr[i].data())){
            clash++;
            //i = (i+1)%NHASH;
            if (++num%2) {
                i = i+ (num+1)/2*(num+1)/2;
                while( i >= NHASH )
                    i -= NHASH;
            }else{
                i = i- num/2*num/2;
                while( i < 0 )
                    i += NHASH;
            }
            
            
        }
        else{
            if (++num%2) {
                i = i+ (num+1)/2*(num+1)/2;
                while( i >= NHASH )
                    i -= NHASH;
            }else{
                i = i- num/2*num/2;
                while( i < 0 )
                    i += NHASH;
            }
            
            //i = (i+1)%NHASH;
            
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
