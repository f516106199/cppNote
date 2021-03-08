#ifndef _SNEAK_H
#define _SNEAK_H
#include"dot.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<iterator>
class dots{
    friend class dot;
public:
    dots(size_t sz=0):v(sz){};
    explicit dots(initializer_list<dot>il):v(il.begin(),il.end()){} // explicit 对只有一个实参的构造函数有效。用于
        //抑制类型转换（即只可以显式，不能隐式转换。）。同时，编译器只会自动地执行一次隐式的类型转换. eg: dots m , m .push_back(3,23f)是错误的;
    dots& operator<<(dot&t){
        v.push_back(t);
        return *this;
    }
    dots&push_back(dot&&t){
        v.push_back(t);
        return *this;
    }
    void show(){
        for(const auto&M:v){
            M.showinfo();
        }
    }
private:
    vector<dot>v;
};
#endif
