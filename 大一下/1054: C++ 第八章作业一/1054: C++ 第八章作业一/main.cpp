//
//  main.cpp
//  1054: C++ 第八章作业一
//
//  Created by apple on 2017/4/24.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class String
{
public:
    string str;
    String ()
    {
        str = "1234567890";
    }
    void reset(string strnow)
    {
        str = strnow;
    }
    void print()
    {
        cout<<str<<endl;
    }
    int getlen()
    {
        return str.size();
    }
    
};
class EditableString
: public String
{
public:
    void Insert(int p, char c)
    {
        int i,j;
        string str1;
        str1=str+"1";
        int len = this->getlen();
        for (i = p-1,j = p; i<len; j++,i++) {
            str1[j]=str[i];
        }
        str1[p-1] = c;
        str=str1;
    }
    void Delete(int p)
    {
        string::iterator it;
        it =str.begin();
        it+=p-1;
        str.erase(it);
        //str[p-1]='\0';
    }
    void Replace(int p, char c)
    {
        str[p-1]=c;
    }
};
int main(int argc, const char * argv[]) {
    EditableString str;
    char c,ch;
    int p,len;
    while (cin>>c) {
        len=str.getlen();
        switch (c) {
            case 'i':
                cin>>p>>ch;
                if (1<=p && p<=len+1) {
                    str.Insert(p, ch);
                }
                str.print();
                break;
            case 'd':
                cin>>p;
                if (1<=p && p<=len) {
                    str.Delete(p);
                }
                str.print();
                break;
            case 'r':
                cin>>p>>ch;
                if (1<=p && p<=len) {
                    str.Replace(p, ch);
                }
                str.print();
                break;
            default:
                goto end;
        }
    }
end:
    
    return 0;
}
