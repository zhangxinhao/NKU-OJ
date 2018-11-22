//
//  main.cpp
//  统计词频_hash
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
#define NHASH  9973
ofstream output("/Users/apple/Documents/2hash.txt");
struct node
{
    char* key ;
    int count = 0;
    node * next = nullptr;
};

node* hashtable[NHASH];

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
void _insert(const char *s)
{
    unsigned int h = _hash2(s);
    node *p;
    for(p=hashtable[h]; p; p = p->next)
        if(strcmp(s,p->key) == 0){
            (p->count)++;
            return;
        }
    p = new node;
    p->count = 1;
    p->key = new char[strlen(s)+1];
    strcpy(p->key, s);
    p->next = hashtable[h];
    hashtable[h] = p;
}

int main(int argc, const char * argv[]) {
    
    clock_t start, end;
    start = clock();
    
    fstream input("/Users/apple/Documents/input2.txt");
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
                _insert(temp.c_str());
                temp.clear();
            }
        input.get(ch);
    }
    int c = 0;
    node* p;
    for(int i=0; i<NHASH; i++)
        for(p = hashtable[i]; p; p = p->next){
            //output.setf(ios::left);
            //output << setw(25)<< p->key << p->count << endl;
            output << p->key << " "<<p->count << endl;
            c++;
        }
    
    
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    cout<< c <<endl;
    return 0;
}

