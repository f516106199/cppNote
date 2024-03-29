# decimal  
float 和 double 都是浮点类型，精度有限, **用于表示近似数** ，不能完全准确的表示小数。  
例如：  
*float x=23.2; double y=23.2; cout<<x==y<<endl;* 结果会输出0。 原因是float类型在转化为double类型之后所表示的二进制码并不相同。**c#中可以使用decimal.** .  
在执行类型转换时，如果是小类型向大类型:如果数据为有符号，转换的数据高位都添符号位。如果为无符号，高位都添0。总之，小类型向大类型转换不会出错。当然，浮点型例外。

***
# 指针和引用  
引用的本质上是一个常量指针（const pointer）。即不能够修改这个指针指向的对象，但是可以修改这个指针指向的对象的值。  
# const 和 constexpr  
## const  
const 用于限定一个变量，说明这个变量是要给常量。不能被改变的量。  
const变量有几个关键点：  
- const变量必须进行初始化     
- const变量只在文件内有效. 即使在头文件中定义了const常量也没用，因为const限定的变量只能在文件内可见。编译器会将看到的const变量的值都替换为常量的值（可以的话），所以每个文件都需要知道 const变量的初始值。又因为const变量不能出现赋值语句，所以每个文件内都必须出现const变量的定义才可以，故const限定的变量只是在文件内个可见。 
**解决方法:** 不论实在头文件还是在源文件中都是用extern const 的形式来定义或者声明变量。且只定义一次变量。  
*eg:: file.h  extern const int x;*  
*file.cpp  extern const int x=32;*  
这样可以做到在多个文件内共享一个const变量。  但是尽量不要使用全局的const变量。 用enum 会更加合适。  
- const 在修饰引用的时候都是指引用的对象是一个常量。
- auto 会过滤掉顶层const
## constexpr 
- constexpr 修饰的变量必须在编译时就能够得到计算。（adding::定义在函数体外的变量都是在编译期间知道地址)
- constexpr 修饰指针时都是指顶层const 
- constexpr 修饰函数时代表返回值可能是一个常量表达式。  constexpr 函数体内不应该有修改函数体外对象的操作。  
- 函数值类型模板参数的实参（argument）必须是一个常量表达时（constexpr）。  
