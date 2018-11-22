//
//  main.cpp
//  记事本
//
//  Created by apple on 2017/4/10.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class node {
public:
    string str;
    node *pNext;
};

class notepad {
public:
    notepad() {
        head = new node;
        head->str = '/';
        head->pNext = NULL;
    }
    ~notepad() { delete head; }
    void creat(int n);
    void insert(int position, string str);
    void replace(int position, string str);
    void print();
    void save();
    bool is_empty();
    int get_length();
    void deleteline(int position);
    void deletenotepad();
private:
    node *head;
};

void notepad::creat(int n) {
    if (n < 0) {
        cout << "输入行数错误！" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        node *pnew, *ptemp;
        ptemp = head;
        int i = n;
        while (n-- > 0) {
            pnew = new node;
            cout << "输入第" << i - n << "行字符：";
            cin >> pnew->str;
            pnew->pNext = NULL;
            ptemp->pNext = pnew;
            ptemp = pnew;
        }
    }
}

void notepad::insert(int position, string str) {
    if (position < 0 || position > get_length() + 1) {
        cout << "输入位置错误！" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        node *pnew, *ptemp;
        ptemp = head;
        pnew = new node;
        pnew->str = str;
        pnew->pNext = NULL;
        
        while (position-- > 1)
        
            ptemp = ptemp->pNext;
        pnew->pNext = ptemp->pNext;
        ptemp->pNext = pnew;
    }
}

void notepad::replace(int position, string str) {
    
    if (position < 0 || position > get_length() + 1) {
        cout << "输入位置错误！" << endl;
        exit(EXIT_FAILURE);
    }
    deleteline(position);
    insert(position, str);
}

void notepad::print() {
    node *p = head->pNext;
    while (p != NULL) {
        cout << endl<<p->str ;
        p = p->pNext;
    }
    cout << endl;
}
void notepad::save() {
    cout<<"请输入文件名字";
    string name;
    cin>>name;
    ofstream myfile("/Users/apple/Documents/Xcode//"+name+".txt");
    node *p = head->pNext;
    while (p != NULL) {
        myfile << endl<<p->str ;
        p = p->pNext;
    }
    //cout << endl;
}

bool notepad::is_empty() {
    if (head->pNext == NULL)
        return true;
    else
        return false;
}

int notepad::get_length() {
    node *p = head->pNext;
    int n = 0;
    while (p != NULL) {
        n++;
        p = p->pNext;
    }
    return n;
}

void notepad::deleteline(int position) {
    if (position < 0 || position > get_length()) {
        cout << "输入位置错误！" << endl;
        exit(EXIT_FAILURE);
    }
    else {
        node *ptemp = head, *pdelete;
        while (position-- > 1)
            ptemp = ptemp->pNext;
        pdelete = ptemp->pNext;
        ptemp->pNext = pdelete->pNext;
        delete pdelete;
        pdelete = NULL;
    }
}

void notepad::deletenotepad() {
    node *pdelete = head->pNext, *ptemp;
    while(pdelete != NULL) {
        ptemp = pdelete->pNext;
        head->pNext = ptemp;
        delete pdelete;
        pdelete = ptemp;
    }
}


int main() {
    notepad note;
    int position = 0,  n = 0;
    string  str;
    bool flag = false;
    
    cout << "请输入需要创建记事本的行数：";
    cin >> n;
    note.creat(n);
    
    char c;
    cout<<"请输入控制符"<<endl<<"'i'=insert,'d'=delete,'r'=replace,'q'=quit,'p'=print"<<endl;
    while (cin>>c) {
        switch (c) {
            case 'i':
                cout << "请输入插入行的位置和字符：";
                cin >> position >> str;
                note.insert(position, str);
                
                cout<<endl;
                cout<<"请输入控制符"<<endl<<"'i'=insert,'d'=delete,'r'=replace,'q'=quit,'p'=print"<<endl;
                break;
            case 'd':
                cout << "请输入要删除行的位置：";
                cin >> position;
                note.deleteline(position);
                
                cout<<endl;
                cout<<"请输入控制符"<<endl<<"'i'=insert,'d'=delete,'r'=replace,'q'=quit,'p'=print"<<endl;
                break;
            case 'p':
                cout << "打印记事本如下：";
                note.print();
                cout<<endl;
                cout<<"请输入控制符"<<endl<<"'i'=insert,'d'=delete,'r'=replace,'q'=quit,'p'=print"<<endl;
                break;
                
            case 'r':
                cout << "请输入要替换行的位置和字符：";
                cin >> position>>str;
                note.replace(position,str);
                
                cout<<endl;
                cout<<"请输入控制符"<<endl<<"'i'=insert,'d'=delete,'r'=replace,'q'=quit,'p'=print"<<endl;
                break;
                
            case 's':
                note.save();
                cout<<"请输入控制符"<<endl<<"'i'=insert,'d'=delete,'r'=replace,'q'=quit,'p'=print"<<endl;
                break;
            case 'q':
                goto end;
                
            default:
                break;
        }
    }
    end:
    note.deletenotepad();
    flag = note.is_empty();
    if (flag)
        cout<<"成功退出"<<endl;
    else
        cout << "退出失败！" << endl;
    
    return 0;
}

