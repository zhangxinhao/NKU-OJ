//
//  main.cpp
//  zifuchuan
//
//  Created by apple on 16/11/21.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
   // freopen("//Users//apple//Documents//Xcode//未命名.rtf", "r", stdin);
    string a;
    cin>>a;
    int i,j,k;
    k=a.size();
    struct jiegou{
        char c;
        int s;
        
        
    };
    jiegou b[80];
    for(i=0;i<80;i++)
    {
        b[i].c=48+i;
        b[i].s=0;
    }
    for (i=0;i<k;i++)
    {
        for(j=0;j<80;j++)
        {
            if (b[j].c==a[i])
            {b[j].s+=1;
                break;
            }
            
        }
    }
    for (i=0;i<80;i++) {
        if (b[i].s!=0) {
            cout<<b[i].c<<" "<<b[i].s<<endl;
            break;
        }
    }
    
    
    
    return 0;
}
