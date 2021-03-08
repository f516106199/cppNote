#include<iostream>
using namespace std;
#include"dot.h"
string static_string;//因为在头文件中声明了该变量，所以该变量不应该是static
dot& dot::addr(const dot&d){//在类的外部定义成员函数需要使用作用域运算符
    if(d.x==x&&d.y==y&&r==d.r){
        netweight+=d.netweight;
    }
    static_string ="dot.cpp";//成员函数的名字查找首先在函数体内查找，然后在类内查找，最后在定义该函数的语句之前查找
    return *this;
}

void change_color(dot&a,dot&b){
    int ia=stoi(a.color_code);
    int ib=stoi(b.color_code);
    a.color_code=to_string((ia+ib)%0xffffff);
}

void change_color(dot&a){
    int ia=stoi(a.color_code);
    a.color_code=to_string((ia+rand())%0xffffff);
}
