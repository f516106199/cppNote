#ifndef _DOT_H
#define _DOT_H
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
extern  string static_string;//在头文件内不要定义全局变量，否则多个文件包含头文件时会出现编译错误
//正确的做法是在头文件中声明变量而不是定义变量，所以用上extern关键字。然后在某一个源文件中的函数体（语句块）外定义即可。
class dot{//类先编译成员，最后编译函数体
    friend class dots;//友元类
    void friend change_color(dot&a,dot&b);//在对函数进行友元的声明时，如果有重载的函数，要分别对每个函数进行友元声明；
    void friend change_color(dot&a);
public:
    using decimal=double;//对于类型成员使用：：运算符来进行访问。而且类型名的定义一般出现在类的前面。防止类外和类内定义了同一个类型名而出吸纳混乱
    dot(decimal x=0,decimal y=0,const std::string& code="#66ccff", const std::string& color="blue", decimal netweight=0,double r=0):
        x(x),y(y),color_code(code),color(color),netweight(netweight),r(r){}//构造函数不能被定义为const ,尽量初始化的顺序与成员顺序一致。
    void showinfo()const{//const 成员函数，即不修改对象
        std::cout<<"x:"<<x<<",y:"<<y<<",color_code"<<color_code<<",colorname"<<color<<",netweight"<<netweight<<std::endl;
    }
    dot(decimal x,decimal y):dot(x,y,"#66ccff"){} //委托构造函数。
    dot(const string& s):x(0),y(0),color_code(s),color("blue"),netweight(0),r(0){}
    void showcnt()const{
        std::cout<<cnt++<<std::endl;//const 修饰的准确说法是this指针，而静态成员属于类而非对象，所以可以对cnt进行更改。
        //同时在const成员函数中可以修改mutable成员。
    }
    dot& addr(const dot& d);
private:
    static int cnt;// 静态成员可以通过对象或者作用域运算符来进行访问
    decimal x;
    decimal y;
    std::string color_code;
    std::string color;
    decimal netweight;
    decimal r;
};
#endif
