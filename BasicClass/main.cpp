#include<iostream>
#include"dot.h"
#include"dots.h"
using namespace std;
//extern string static_string;
const int z=12; //data segment readonly
int x= 32;// data  segment
static int y=23; //datasegment
extern void change_color(dot&a,dot&b);
void (*p)(dot&a,dot&b)=change_color;//函数地址在text segment
int main(){
    cout<<reinterpret_cast<void*>(&x)<<endl;
    cout<<reinterpret_cast<void*>(&y)<<endl;
    cout<<reinterpret_cast<void const *>(&z)<<endl;
    cout<<(void*)p<<endl;
    dots m(3.2f);
    m.push_back(dot("蓝色"));
    m.show();
    return 0;
}
