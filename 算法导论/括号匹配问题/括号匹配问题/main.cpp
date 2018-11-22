//
//  main.cpp
//  括号匹配问题
//
//  Created by apple on 2018/3/13.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

stack<int> S;
char input[100];
char output[100];

int main(int argc, const char * argv[]) {
    while(scanf("%s",input)!=EOF)
    {
        int i;
        for(i=0;input[i]!=0;i++)
        {
            if(input[i]=='(')
            {
                S.push(i);
                output[i]=' ';
            }else if(input[i]==')')
            {
                if(!S.empty())
                {
                    S.pop();
                    output[i]=' ';
                }else
                    output[i]='?';
            }else
                output[i]=' ';
        }
        while(!S.empty())
        {
            output[S.top()]='$';
            S.pop();
        }
        output[i]=0;
        cout << input <<endl;
        cout << output <<endl;
        //puts(input);
        //puts(output);
    }
    return 0;
}
