//
//  main.cpp
//  表达式求值
//
//  Created by apple on 2017/10/19.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cmath>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

//获取运算符优先级
int getRink(char opt){
    if (opt == '+' || opt == '-') return 1;
    if (opt == '*' || opt == '/' || opt == '%') return 2;
    if (opt == '^') return 3;
    if (opt == '(') return 0;
    else return -1;
}

//中缀表达式转为后缀表达式
int postfix(string &str_post, string &str_mid){
    stack<char> opt;
    bool flag = false;
    while (!opt.empty())
        opt.pop();
    for (int i = 0; str_mid[i] != '\0'; i++){
        // 数字处理
        if (str_mid[i] >= '0' && str_mid[i] <= '9'){
            if (flag) str_post += '&';
            else flag = true;
            while ('0' <= str_mid[i] && '9' >= str_mid[i]){
                str_post += str_mid[i];
                i++;
            }
            i--;
        }
        //左括号处理
        else if (str_mid[i] == '('){
            opt.push(str_mid[i]);
        }
        //右括号处理
        else if (str_mid[i] == ')'){
            while (opt.top() != '(' && !opt.empty()){
                str_post += opt.top();
                opt.pop();
                flag = false;
            }
            if (opt.empty()) return -1;
            if (opt.top() == '('){
                opt.pop();
            }
        }
        //运算符处理
        else if (str_mid[i] == '+' || str_mid[i] == '-' || str_mid[i] == '*' || str_mid[i] == '/' || str_mid[i] == '%' || str_mid[i] == '^' ){
            int a1 = getRink(str_mid[i]);
            if (a1<0) return -1;
            int a2;
            while (!opt.empty()){
                a2 = getRink(opt.top());
                if (a2<0) return -1;
                if (a1 == a2 && a1 == 3) {
                    break;
                }
                if (a1 <= a2){
                    str_post += opt.top();
                    opt.pop();
                    flag = false;
                }
                else break;
            }
            opt.push(str_mid[i]);
        }
        else return -1;
    }
    // 运算符出栈
    while (!opt.empty()){
        if (opt.top() == '(') return -1;
        str_post += opt.top();
        opt.pop();
    }
    return 0;
}

//加减乘除结果计算
double getResult(double a, double b, char opp){
    if (opp == '+') return a + b;
    if (opp == '-') return a - b;
    if (opp == '*') return a*b;
    if (opp == '/') return a/b;
    if (opp == '%') return (int)a % (int)b;
    if (opp == '^') return pow(a, b);
    else return 0;
}

//后缀表达式计算结果
double compute(string str){
    stack<double>  data;
    double temp, op1, op2;
    while (!data.empty()) data.pop();
    for (int i = 0; str[i] != '\0'; i++){
        if ('&' == str[i]) continue;
        //数值处理
        else if ('0' <= str[i] && '9' >= str[i]) {
            temp = 0;
            while ('0' <= str[i] && '9' >= str[i]){
                temp = temp * 10 + str[i] - '0';
                i++;
            }
            i--;
            data.push(temp);
        }
        //运算符处理
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%'
                 || str[i] == '^'){
            if (data.size()<2){ return -1; }
            op1 = data.top(); data.pop();
            op2 = data.top(); data.pop();
            temp = getResult(op2, op1, str[i]);
            data.push(temp);
        }
        else return -1;
    }
    if (data.size() != 1){
        return -1;
    }
    return data.top();
}

int main(int argc, const char * argv[]) {
    
    vector<string> data_store;
    vector<string> str_post;
    string line;
    //读取数据
    fstream data_input("/Users/apple/Downloads/input.txt");
    if(data_input.is_open())
    {
        while( getline (data_input,line) )
        {
            data_store.push_back(line);
        }
    }
    str_post.resize(data_store.size());
    //写入数据
    ofstream data_output("/Users/apple/Downloads/output.txt");
    for(int i = 0; i < data_store.size(); i++){
        if(!postfix(str_post[i], data_store[i])){
            if (compute(str_post[i]) != -1) {
                data_output << setiosflags(ios::fixed) << setprecision(2)<<compute(str_post[i]) <<endl;
            }else {
                data_output << "ERROR IN INFIX NOTATION" <<endl;
            }
        }else{
            data_output << "ERROR IN INFIX NOTATION" <<endl;
        }
    }
    return 0;
    
}
