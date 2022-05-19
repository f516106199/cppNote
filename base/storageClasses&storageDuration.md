# storageClasses of c++   
![1](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191128194021/CStorageClass1.png)

[geeksforgeeks](https://www.geeksforgeeks.org/storage-classes-in-c-with-examples/)  

[cppreference](https://zh.cppreference.com/w/cpp/language/storage_duration)
## static auto mutable external register
1. static:  
- 当static用于声明函数的局部（自动）变量时，意味着这个变量只会被定义一次，之后每一次调用这个函数都不会重新定义该static变量。  
- 当static 用于类内时，表明该数据成员or成员函数属于整个类而不属于对象。通常意味着应该在类的外部定于改变量。同时应该满足单个变量定义一次的原则，所以一般在某个源文件的所有函数外部定义。如果在源文件的某个函数内部定义，会报错。或许静态成员变量在函数内部定义时可能会出现多次定义的情况。当static用于声明静态成员函数时，静态成员函数只能调用类的static成员，因为静态成员函数也没有this  指针，也同时意味着不能将静态成员函数声明为const的。  
- 在C标准中，static可以用于修饰函数。 表明该函数只在定义该函数的编译单元可见，其他文件无法使用，可以被视为文件内私有的。  
2. auto 
- 新版本的auto定义的变量不仅可以用于定义automatic storage duration 变量，还可以用于定义全局变量等等。
3- register  
-  该关键字在c++11之后已经被弃用。

## storage duration 
Storage duration is the property of an object that defines the minimum potential lifetime of the storage containing the object.
### static storage duration
Global variables, including those inside namespaces, and variables marked with the duration keyword static have static storage duration.  
Global variables are initialized during program initialization (i.e. the period before the program actually starts execution of your main or wmain function). They are initialized  in the order in which they are defined in the source code.      
Local statics are zero-initialized the first time program execution reaches the block containing the local static. Typically, they will be initialized to their specified values or initialized by calling the specified constructor at that point. The value assignment or construction phase is not  required until the program reaches and executes the statement, except in very rare circumstances. Once a local static is initialized, the initialization specified with its declaration will never run again. This, of course, is just what we would expect of a local static. If it kept initializing itself every time the program reached its definition line, then it would be the same as a non-static local.  
### automatic storage duration
Within a block, an object has automatic duration if it is defined without the new operator to instantiate it, and without a storage duration keyword, although it can optionally have the register keyword. This means the object is created at the point when it is defined and is destroyed when the program exits the block its variable was declared in, or when a new value is assigned to its variable.

Note: The auto keyword used to be a way of explicitly selecting automatic storage duration. In C++11, that usage was removed. It now is the equivalent of the var keyword in C#. If you try to compile something using the old meaning of auto, you'll receive a compiler error since auto as a type specifier must be the only type specifier.  

### dynamic storage duration
Dynamic duration is the result of using either the new operator or the new[] operator. The new operator is used to allocate single objects, while the new[] operator is used to allocate dynamic arrays. You must keep track of the size of a dynamically allocated array. While the C++ implementation will properly free a dynamically allocated array, provided you use the delete[] operator, there is no easy or portable way to determine the size of that allocation. It will likely be impossible. Single objects are freed with the delete operator.

When you allocate memory using new or new[], the return value is a pointer. A pointer is a variable that holds a memory address. In C#, if you set all your references to an object to null or some other value, then the memory is no longer reachable in your program, so the GC can free that memory for other uses.

In C++, if you set all of your pointers to an object to nullptr or some other value, and you cannot figure out the original address using pointer arithmetic, then you have lost your ability to release that memory using the delete or delete[] operators. You have thereby created a memory leak. If a program leaks enough memory, eventually it will crash because the system will run out of memory addresses for it. Even before that, though, the computer will slow horribly, as it is forced to increase paging to accommodate the ever-increasing memory footprint of your program (assuming it has virtual memory, which is absent from most smart phones).

Note: A const pointer, such as someStr in the statement const wchar_t* someStr = L"Hello World!"; is not a dynamic duration pointer. That memory is just part of the program itself. If you try to call delete or delete[] on it, the program will simply crash. A string is an array of characters, however, so if it were okay to delete it, then the delete[] operator would be the correct one to use.

When dealing with dynamic memory, to eliminate potential leaks and limit the possibility of other related bugs, you should always use a smart pointer such as std::unique_ptr or std::shared_ptr. We will discuss these in the chapter that covers pointers.

### thread storage duration   
to be continued..  




