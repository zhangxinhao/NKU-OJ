//
//  main.cpp
//  统计词频_map
//
//  Created by apple on 2017/11/1.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <ctime>
using namespace std;
ofstream output("/Users/apple/Documents/map.txt");

void display_map(map<string,int> &wmap);
int c = 0;
int main(int argc, const char * argv[]) {
    
    clock_t start, end;
    start = clock();
    
    fstream input("/Users/apple/Documents/input.txt");
    
    map<string,int> wmap;
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
                wmap[temp]++;
                temp.clear();
            }
        input.get(ch);
    }
    display_map(wmap);
    
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    cout << c << endl;
    return 0;
}

void display_map(map<string,int> &wmap)
{
    map<string,int>::const_iterator map_it;
    for(map_it=wmap.begin();map_it != wmap.end();map_it ++)
    {
        output.setf(ios::left);
        //output.width(16);
        output << setw(25)<< map_it->first << map_it->second << endl;
        c++;
        
    }
}
