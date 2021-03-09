## new and delete expression
tips: memory leak: **memory is not deallocated until program terminates**
### new operator  
1.new 处理动态数组时：  
>表达式中除了最后一维，其余都应该是constexpr 。  
eg:
``` c++ 
int n=32;
const (constexpr) int m=2;
auto ptr= new int [n][2][m]   √  // 编译器得先知道 int[2][m]的具体大小，所以m应该在编译期间可知。
auto ptr1= new int [n][n]  ×
```
>动态数组里面元素的初始化。 
``` c++
auto ptr1=new int [2]() //进行值初始化，里面的每个元素初始值为0
auto ptr2 =new int [2]  // 进行默认初始化，里面的元素值未定义
auto ptr3 = new string[2] // 对于非简单类型，实际都是默认初始化，调用了默认构造函数
auto ptr4= new string [5]{"fjksdljf","fjkdsfj",“好多"}// 前面三进行拷贝构造，后面的值初始化。  
2. new 处理单个对象
··· c++
auto ptr1=new string() // 默认构造 
auto ptr2=new int ()// 值初始化为0
auto ptr3 new int ;// 默认初始化，值未定义  
```
### delete
delete 进行两种操作。1.指针所指向对象的析构（销毁），2.所指位置内存的释放。  
1.delete  
>delete 用于空指针或者指向某个对象的指针。
>delete如果用于指向非法区域的指针，则可能造成内存被破坏，即被释放多次的可能。
>delete用于指向简单类型的指针。 则没有析构操作，进行内存释放即可。
>delete用于nullptr时安全的。
>不要用于指向void的指针  
2.delete[]  
>delete[]用于动态数组。  
>delete[]实现指向的动态数组的每个元素的析构以及内存的释放。  
>同样不能将delete[]用于非法指针，可用于nullptr指针。  
>delete与[]结合的优先级高于*lambda*表达式，所以当delete用于*lambda*表达式时要使用圆括号。  
>不要用于指向void的指针。

## allocator
allocator 是一个类模板。用其分配的内存是为构造的。
``` c++
allocator<string>al;
auto ptr=al.allocate(11);
al.construct(ptr,"dfjksl");
al.construct(ptr+1,"fjds");
al.destory(ptr);
al.deallocate(ptr,11);
```
**to be continued..**  
## smart pointers
shared_ptr && weak_ptr
1.shared_ptr
不要混用shared_ptr和普通指针  
- shared_ptr
>不要用智能指针包裹的普通指针初始化另一个智能指针。  
>不要对智能指针包裹的普通指针使用delete  
>一旦使用了智能指针，尽量不要再使用普通指针。  
>内部实现采用引用计数  
- weak_ptr  
>用于和shared_ptr搭配使用，不会影响引用计数。  
- unique_ptr  
>不可以进行赋值，拷贝操作，但是可以进行reset和赋予nullptr  
>release 会返回绑定的普通指针。如果没有用一个指针保存返回值，则可能造成内存泄漏  

### shared_ptr 和 unique_ptr的删除器
shared_ptr 采用的是运行时删除器，也就是说，我们再创建一个shared_ptr的对象的时候，我们并没有指定删除器类型的模板类型参数，在编译时并没有绑定删除器，而是在运行时进行了删除器的绑定。  
通常，类成员的类型在运行时是不能改变的，然而我们可以在运行时顺便改变删除器的类型，故类并没有直接保存删除器将之作为成员，删除器是间接保存的，因此调用删除器会产生跳转操作。  
unique_ptr 采用的是编译时删除器，也就是说，在创建一个unique_ptr的的对象的时候，我们就可以指定删除器的类型，确定模板类型参数的类型。 因此unique_ptr将删除器保存为自己的成员，减少了间接调用删除其的开销，效率更高。






