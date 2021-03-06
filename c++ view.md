# C++面试问题

### 0. 设计模式

* 设计模式是一套被反复使用，经过分类编目的、代码设计经验的总结。

* 单例模式：保证一个类仅有一个实例，并提供一个访问该例的全局访问点。

  适用于：当类只能有一个实例而且客户可以从一个众所周知的访问点访问它时；当这个唯一实例应该是通过子类化可扩展的，并且客户应该无需更改代码就能使用一个扩展的实例时。

* 在c++中，单例模式是一种反模式，使用频率正在逐渐减少。

  单例可以通过返回相同缓存对象的静态构建方法来识别。

  私有化构造函数

  2. 使用类的私有静态指针变量指向类的唯一实例

  3. 使用一个公有的静态方法获取该实例

  ```c++
  //懒汉模式
  class Singleton {
  private:
      static Singleton* ptr;
  
      class Deletor { //定义一个嵌套类 使用嵌套类防止内存泄漏
  	public:
  		~Deletor() {  
  			if(Singleton::ptr != NULL)
  				delete Singleton::ptr;
  		}
  	};
  	static Deletor deletor;
      //构造函数等
      
  public:
      static Singleton* getPtr() {
          if(ptr == NULL) {
              ptr = new Singleton(); //会出现线程安全问题
          }
          return ptr;
      }
  };
  Singleton* Singleton::ptr = nullptr;
  Singleton::Deletor Singleton::deletor;
  
  //饿汉模式  没有线程安全问题 但是静态变量实例化 和调用静态函数的初始化顺序不确定 当调用函数时 会有可能得到一个空例
  class Singleton {
  private:
      static Singleton instance;
      //构造函数等
  public:
      static Singleton& getInstance() {
          return instance;
      }
  }
  Singleton Singleton::instance;
  
  //懒汉模式  无线程安全问题和初始化顺序问题
  class Singleton {
  private:
      //构造函数等
  public:
      static Singleton& getInstance() {  
          static Singleton instance;
          return instance;
      }
  }
  ```

     

  

* 工厂模式：定义一个用于创建对象的接口，让子类决定实例化哪一个类。Factory Method 使一个类的实例化延迟到其子类。

  适用于：当一个类不知道它所必须创建的对象的类的时候；当一个类希望由它的子类来指定它所创建的对象的时候；当类将创建对象的职责委托给多个帮助子类中的某一个，并且你希望将哪一个帮助子类是代理者这一信息局部化的时候。 

  

### 1. c++中的四个强制类型转换

* static_cast

  static_cast（静态转换）本质上是c语言强制转换的替代品，c++中的任何的隐式转换都是使用static_cast来实现的。

  另外还能用于基类和派生类之间指针或引用的转换；
  \- 进行上行转换（把派生类的指针或引用转换成基类表示），是安全的；
  \- 进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是不安全的；

```c++
char a = 'a';
int b = static_cast<int>(a);//将char型数据转换成int型数据  用于基础数据类型之间的转换 这个安全性需要开发者维护。  没有类型检查

//类指针或引用强制转换
Base* base = new Base();
Derived* derived = static_cast<Derived*>(base);//将基类指针或引用转换成派生类表示  下行转换是不安全的  因为没有动态类型检查

Derived* derived1 = new Derived();
Base* base1 = static_cast<Base>(derived1);//将派生类的指针或引用转换成基类表示  上行转换是安全的 
```

* const_cast

  常量指针转化非常量的指针、常量引用转化非常量引用，并且仍然指向原来的对象。

  const_cast一般用于修改指针。

```c++
const int a = 5;
int *p = &a; //因为a是常量  此时无法修改*p的值
int *ptr = const_cast<int*>(p); //去除常量
*ptr ++; //现在可以进行修改
```

​	并没有在真正去除变量的const属性，去除了指针的const属性，间接修改

* dynamic_cast

  用于动态类型转换。只能用于含有虚函数的类，用于类层次间的向上和向下转化。只能转指针或引用。

  ```c++
  Base* base = new Base();
  Derived* derived = new Derived();
  
  Base* der2base = dynamic_cast<Base*>(derived); //这个成功转换 子类到基类的转换
  Derived* base2der = dynamic_cast<Derived*>(base); //基类转换成子类 会在程序运行时进行动态类型检查  因为虚函数的存在 基类的指针指向子类 调用方法时只会顺着虚函数表找到子类的方法。通过虚函数的性质 就发现转换到的新类型不是原类型的子类 就会将其置为nullptr。
  ```

  

* reinterpret_cast

  几乎什么都可以转，比如将int转指针，可能会出问题，尽量少用；

  推荐使用的地方：指针转向足够大的整数类型。

  ```c++
  int *ptr = new int(123);
  uint32_t pter_addr = reinterpret_cast<uint32_t>(ptr); //将指针ptr的地址的值 转换成了无符号int类型
  ```

  

* 为什么不使用C++的强制转换？

C++的强制转换表面上看起来功能强大什么都能转，但是转化不够明确，不能进行错误检查，容易出错。

### 2. C++编译器为类产生的四个缺省函数

* **默认构造函数**

  专门用于初始化成员变量

  **什么时候必须用到初始化成员列表 **：类的成员是常量、是对象且没有无参构造函数、是引用。

  **构造函数的调用顺序：**

  1. 先调用基类构造函数
  2. 按声明顺序初始化数据成员
  3. 最后调用自己的构造函数

* **拷贝构造函数**

  ```c++
  class Complex {
  private:
      int x, y;
  public:
      Complex(int x_, int y_) : x(x_), y(y_) {} 
      Complex(const Complex&); //默认的拷贝构造函数
  };
  Complex c1(1,2);
  Complex c2(c1); //1.调用拷贝构造函数  
  Complex c2 = c1; //调用拷贝构造函数  
  //调用拷贝构造函数就不会再调用构造函数
  
  void func(Complex c) {  //2.
      Complex c3(2,2);
      return c3;  //3.
  }
  ```

  1. 当类的一个对象去初始化该类的另一个对象

  2. 当函数的形参是类的对象，调用函数进行形参和实参的结合

  3. 函数的返回值是类的对象，调用函数返回值

  4. **重写拷贝构造函数**

     当构造函数涉及到动态存储分配空间时
     
     所以在对含有指针成员的对象进行拷贝时，必须要自定义拷贝构造函数，使拷贝后的对象指针成员有自己的内存空间，即进行**深拷贝**，这样就避免了内存泄漏发生。
     
     浅拷贝只是对指针的拷贝，拷贝后两个指针指向同一个内存空间，深拷贝不但对指针进行拷贝，而且对指针指向的内容进行拷贝，经深拷贝后的指针是指向两个不同地址的指针。
     
     浅拷贝带来问题的本质在于析构函数释放多次堆内存，使用std::shared_ptr，可以完美解决这个问题。
     
     ```c++
     class Student
     {
     private: 
     	int num;
     	char *name;
     public:
     	Student();
     	~Student();
     	Student(const Student &s);//拷贝构造函数，const防止对象被改变
     };
     Student::Student()
     {
     	name = new char(20);
     	cout << "Student" << endl;
     }
     Student::~Student()
     {
     	cout << "~Student " << (int)name << endl;
     	delete name; 
     	name = NULL;
     }
     Student::Student(const Student &s)
     {
     	name = new char(20);
     	memcpy(name, s.name, strlen(s.name));
     	cout << "copy Student" << endl;
     }
      
     int main()
     {
     	{// 花括号让s1和s2变成局部对象，方便测试
     		Student s1;
     		Student s2(s1);// 复制对象
     	}
     	system("pause");
     	return 0;
     }
     ```
     
     

* **析构函数**

  对象生命周期结束时 调用

  **调用顺序与构造函数相反**

  生成多个对象时，构造函数按照生成顺序调用，析构函数相反， 相当于一个栈。

  但是函数或main内存在静态对象时，一般为最后一个析构。

* **赋值函数**

  系统自定的运算重载符=函数
  
  ```c++
  Complex c1(1,2);
  Complex c2(3,4);
  c2 = c1;
  ```

### 3. 静态函数存在的意义

* 通过类的静态成员函数访问类的静态私有成员

* 类的构造函数是私有时，只能通过静态成员函数来调用构造函数

* 静态成员函数不具体作用与某个对象，只能访问静态成员，不能访问非静态成员变量

  ```c++
   class C {
  private:
      int w,h;
      static int n1;  //静态成员变量
      static int n2;
  public:
      static void printTotal() {
          cout << n1;
          cout << n2;
      };  //静态成员函数 为整个类共有  不需要隐式指针参数的传递
  };
  int C::n1 = 1; //必须在定义类的文件中对静态成员变量进行一次声明或初始化，
  int C::n2 = 2;
  
  C::printTotal(); 
  C c1(1,1);
  c1.printTotal();
  ```

### 4. 基础概念

* **OOP**  的设计思想是 把数据结构和对数据结构进行操作的方法 封装成一个个对象

* **OOP**的三大特征：封装、继承、多态  

* **类**  是把一些具有共性的对象归类后形成 一个集合

* 在类的内部定义成员函数，会变成**内联函数**，它在函数调用的地方在编译阶段会进行代码替换

* 成员函数通过  **this指针指向对象的首地址**  来区分不同对象的成员数据

* **常对象 ** 是指在任何场合都不能对其成员的值进行修改的对象

* **抽象类**  不用来定义对象 只作为一种基本类型用作继承的类  其会定义纯虚函数

* **运算重载符** 使用户定义数据类型的数据的操作于内定义的一致

  不允许重载的运算符：

  1. .*（成员指针访问运算符号）
  2. ：：域运算符
  3. Sizeof 长度运算符号
  4. ？：条件运算符号
  5. .（成员访问符）
  
* **父类写了virtual函数，子类覆盖它的复写函数，会隐形继承virtual，virtual可加可不加，一样会实现多态。**

* 虚函数的实现使用了虚函数表。

* **回调函数**：预先在系统对函数进行注册，当某个事件发生时，再调用这个函数对事件进行响应。在函数前面加上CALLBACK

* 全局对象的构造函数会在main函数之前执行。

* **实时系统**能在特定时间完成特定的任务， 实时性和可靠性。

* 全局变量存储在静态数据区，局部变量存储在堆栈中。

* **堆栈溢出 是没有回收垃圾资源**。

* switch的参数不能为实型。

* c++不是类型安全的， 两个不同类型的指针可以强制转换（reinterpret_cast）

* **多态** ：是指相同的操作或函数、过程可作用于多种类型的对象上并获得不同的结果。不同的对象，收到同一消息可以产生不同的结果，这种现象称为多态。

* **多态实现的原理**：

  1. 当类中存在虚函数时，编译器会在类中自动生成一个虚函数表

  2. 虚函数表是一个存储类成员函数指针的数据结构

  3. 虚函数表由编译器自动生成和维护

  4. virtual修饰的函数会被编译器放入虚函数表中

  5. 存在虚函数时，编译器会为对象自动生成一个指向虚函数表的指针（vptr指针） 是一个成员指针变量
  
* 创建子类对象时，会先创建父类对象，而父类的构造方法中调用虚函数，并不会发生多态，父类只会调用自己的虚成员函数。这个与虚表指针（vptr）的分步初始化有关。

  创建子类对象，编译器的执行顺序：

  1. 对象在创建时，由编译器对虚表指针进行初始化
  2. 子类的构造会调用父类的构造函数，虚表指针会先指向父类的虚函数表
  3. 子类构造的时候，虚表指针会再指向子类的虚函数表
  4. 对象的创建完成后，虚表指针最终的指向才确定
### 5. 拷贝构造函数与赋值函数对比

* 都是将一个对象copy到另一个对象

* 拷贝构造函数需要新建立一个对象

### 6. 函数重载与虚函数

* **函数重载：**

  一个同名函数完成不同的功能，编译系统在编译阶段通过函数参数个数、类型的不同，函数的返回值来确定调用哪个函数，实现了**静态的多态性**。**不能仅靠返回值的不同来实现函数重载。**

  **构造函数可以重载，析构函数不可以重载。**

  调用重载函数有三种可能的结果：

  * 编译器找到一个与实参最佳匹配的函数，并生成调用该函数的代码
  * 找不到任何一个函数与调用的实参匹配，编译器发出无匹配的错误信息
  * 有多于一个函数可以匹配，发生错误，二义性调用

  

* **虚函数：**(为了使基类指针 能够访问派生类的成员函数)  函数覆盖 重写

  在基类中使用关键字**virtual**申明一个函数为虚函数，含义就 是该函数的功能可能将在某个派生类中定义或者在基类的基础上进行扩展。系统在运行阶段才能动态的决定该调用哪一个函数，实现了**动态的多态性**。

  虚函数有虚拟指针和虚函数表，虚拟指针是虚函数的接口。

  **那么虚表指针在什么时候，或者说在什么地方初始化呢？**

  答案是在构造函数中进行虚表的创建和虚表指针的初始化。还记得构造函数的调用顺序吗，在构造子类对象时，要先调用父类的构造函数，此时编译器只“看到了”父类，并不知道后面是否后还有继承者，它初始化父类对象的虚表指针，该虚表指针指向父类的虚表。当执行子类的构造函数时，子类对象的虚表指针被初始化，指向自身的虚表。
  
  
  
  **目的**：通过基类指针对所有派生类（包括直接派生和间接派生）的成员变量和成员函数 进行访问，尤其是成员函数，如果没有多态  只能访问成员变量。
  
  
  
  **注意：虚函数要么设为纯虚函数，要么有定义，要不然无法生成虚函数表。**
  
  声明为纯虚函数，类为抽象类，无法实例化。在虚函数的后面加=0
  
  区别：https://www.jianshu.com/p/c8e74ef95091
  
  
  
  **凡是基类定义有虚函数，则基类需要定义虚析构函数（规则如上）**：虚析构函数是为防止析构不彻底，导致内存泄漏。
  
  虚析构函数使得在删除指向子类对象的基类指针时  可以调用子类的析构函数 达到释放子类中堆内存的目的， 从而防止内存泄露。
  
  
  
  **内联函数和构造函数不能为虚函数**：对于基类的构造函数，它仅仅是在派生类构造函数中被调用，将构造函数声明为虚函数没有意义。
  
  
  
* 静态关联

  在多态中，程序在编译阶段就能确定实际执行动作，则成为静态关联。

* 动态关联

  在多态中，等到程序运行才能确定的叫做动态关联。

  
  
* **函数隐藏**

  类成员函数隐藏是指派生类的函数屏蔽了与其同名的基类函数。

  1. 派生类的函数与基类的函数同名，但是参数不同，有无virtual，基类的函数将被隐藏。（与重载不同）
  2. 派生类的函数与基类的函数同名，参数相同，但是基类函数没有virtual，基类的函数将会被隐藏。（与覆盖不同）

### 7. 类模板与模板类

* 类模板，是建立一个通用类，其数据成员、成员函数的返回值类型和形参类型不具体指定，用一个虚拟的类型来代表。**使用类模板定义对象时，系统会实参的类型来取代类模板中虚拟类型从而实现了不同类的功能**。

* 类模板的派生一定是类模板

  ```c++
  template<tyname T>
  class Compare {
  public:
      Compare(T i, T j) {
          x = i;
          y = j;
      }
  private:
      T x, y;
  }; //这是一个类模板
  
  Compare<int>com1(3,7); //Compare<int>是模板类
  ```

* 模板类是类模板实例化的的一个产物。

* 模板类可以派生新的模板类，也可以派生非模板类

### 8. 当一个类A 中没有生命任何成员变量与成员函数,这时sizeof(A)的值是多少，如果不是零，请解释一下编译器为什么没有让它为零

* 肯定不是零。举个反例，如果是零的话，声明一个class A[10]对象数组，而每一个对象占用的空间是零，这时就没办法区分A[0],A[1]…了。
* 空类大小等于1，编译器为了区分不同的类，在类中加了一个char型。
* 这涉及到c++的空类概念
* c++的空类有以下成员函数
  1. 缺省构造函数
  2. 缺省拷贝构造函数
  3. 缺省析构函数
  4. 缺省赋值运算符

### 9. delete 与 delete[]的区别

* delete只会调用一次析构函数，delete[]会调用每个成员的析构函数。

* 子类析构时 会调用父类的析构函数

  次序是先派生后基类

###   10. 继承的优缺点

* 优点：
  1、类继承是在编译时刻静态定义的，且可直接使用，
  2、类继承可以较方便地改变父类的实现。

* 缺点：
  1、因为继承在编译时刻就定义了，所以无法在运行时刻改变从父类继承的实现
  2、父类通常至少定义了子类的部分行为，父类的任何改变都可能影响子类的行为
  3、如果继承下来的实现不适合解决新的问题，则父类必须重写或被其他更适合的类替换。这种依赖关系限制了灵活性并最终限制了复用性。

### 11. 堆和栈

* **stack**

  **由编译器自动分配释放,  存放函数的参数值,  局部变量的值等**

* **heap**

  一般由程序员分配释放,  若不手动释放, 程序结束由OS回收

### 12. 何时需要预编译

* 总是使用的不经常改动的大型代码体

* 程序由多模块组成，所有模块都使用一组标准的包含文件和相同的编译选项

### 13.  多态的作用

* 隐藏实现细节，代码模块化；扩展代码模块，实现代码重用；

* 接口重用：为了类在继承和派生的时候， 使用家族中任意一类的实例的某一属性的正确调用

### 14. 常引用

* 如果既要利用引用提高程序的效率，又要保护传递给函数的数据不在函数中被改变，就应使用常引用。

### 15. 引用和指针的区别

* 引用必须初始化，指针不用
* 引用初始化不能被改变，指针可以改变所指的对象
* 不存在指向空值的引用，存在指向空值的指针

### 16. 如何引用一个已经定义过的全局变量

* 可以用引用头文件的方式，也可以用extern关键字，如果用引用头文件方式来引用某个在头文件中声明的全局变理，假定你将那个变写错了，那么在编译期间会报错，如果你用extern方式引用时，假定你犯了同样的错误，那么在编译期间不会报错，而在连接期间报错。
* extern可以置于变量或者函数前，以标示变量或者函数的定义在别的文件中，提示编译器遇到此变量和函数时在其他模块中寻找其定义。此外extern也可用来进行链接指定。

### 17. 数组和指针的区别

* 数组要么在静态存储区，要么在栈上被创建。指针可以随时指向任意类型的内存块。

### 18. 内存的分配方式

* 静态存储区，程序编译时分配好了，全局变量和常量，静态变量。

* 栈上分配，局部变量，内存有限。

* 堆上分配，也称动态分配， new,malloc分配内存，delete,free释放内存

  ```c++
  int *p = new int(); 
  delete p;
  
  int *p = new int[len];
  delete []p;
  
  vector<vector<int>> arr(n, vector<int>(m));
  
  myClass *p = new myClass[len];
  delete []p;
  ```

* **new和malloc之间的区别**

  1. 基本属性

     new/delete是C++关键字，需要编译器的支持。malloc/free是库函数，需要头文件支持。

  2. 申请内存所在位置不同

     new操作符是从**自由存储区**上为对象分配内存空间，而malloc函数从堆上动态分配内存。

     **自由存储区**是C++基于new操作符的一个抽象概念，凡是通过new操作符进行内存申请， 该内存即为自由存储区。堆是操作系统维护的一块特殊内存，用于程序的内存动态分配。

     自由存储区不仅可以是堆， 还可以是静态存储区，都由**operator new**在哪里为对象分配内存决定。

  3. 内存分配成功时返回类型安全性 

     new内存分配成功时，返回的是对象类型的指针，类型严格与对象匹配，无需进行类型转换，**new是类型安全性的操作符**

     malloc内存分配成功返回的是void*，需要通过强制类型转换。

  4. 内存分配失败时的返回值

     new 内存分配失败时，会抛出异常，不会返回NULL；malloc内存分配失败时会返回NULL

  5. 是否需要指定内存大小

     new 分配内存无需指定内存块的大小，编译器会根据类型信息自行计算，

     malloc需要显式的指出所需内存的尺寸。

     ```c++
     A* ptr = new A;
     int* ptr = new int;
     int* ptr = (int*)malloc(sizeof(int));  //需要显式指定所需内存块大小
     ```

  6. 是否调用构造函数/析构函数

     new分配对象内存时：调用operator new函数分配一块内存空间；运行对应的构造函数 构造对象；返回一个指向该对象的指针。

     delete释放内存时：调用对象的析构函数；调用operator delete函数释放内存空间。

  7. malloc和free的实现过程

     * malloc采用内存池的方式，先申请大块内存作为堆区，然后将堆区分为多个内存块，以块作为内存管理的基本单位。
     * 空闲存储空间以空闲链表的方式组织，每个块包含一个长度、一个指向下一块的指针以及指向自身存储空间的指针。
     * 申请内存时，malloc会扫描空闲链表，直到首次找到一个足够大的块为止。
     * 该块与请求的大小相符，直接将其从链表中移走并返回给用户，如果块过大，将该块的尾部空间分给用户，更新块的头部信息。
     * 释放内存时，搜索空闲链表，找到可以插入被释放块的合适位置。如果与释放块相邻的一边为空闲块，直接合并为更大的块，减少内存碎片。

  8. 对数组的处理

     new[]和delete[]

  9. 是否可以被重载
  
     operator new和operator delete 可以被重载
  
  10. 是否能够直观地重新分配内存
  
     使用malloc分配的内存后，如果在使用过程中发现内存不足，可以使用realloc函数进行内存重新分配实现内存的扩充。realloc先判断当前的指针所指内存是否有足够的连续空间，如果有，原地扩大可分配的内存地址，并且返回原来的地址指针；如果空间不够，先按照新指定的大小分配空间，将原有数据从头到尾拷贝到新分配的内存区域，而后释放原来的内存区域。
  
     new没有这样直观的配套设施来扩充内存。
  
* delete和free的混用问题

  1. 当申请的空间是C++内置类型时，可以混用

  2. 当申请的空间是自己定义类型时，

     * 若没有析构函数，delete和malloc能够混用。

     * 若有析构函数,

       malloc申请的空间能够用delete和free释放，且用delete释放时不能加[]

       new申请的空间不能用free释放，只能用delete释放。

### 19. 四个智能指针

* 智能指针是一个类对象，负责自动释放所指向的对象。

  当一个类中，存在一个指向另一个类对象的指针时，对指针运算符进行重载，那么当前类对象可以通过指针像调用自身成员一样调用另一个类的成员。

*   智能指针的作用就是为了保证使用堆上对象的时候，对象一定会被释放，但只能释放一次，并且释放之后指向该对象的指针应该马上归 nullptr。

* **auto_ptr**已弃用

  避免因潜在的内存问题导致程序崩溃：auto_ptr进行赋值操作时候，被赋值的取得其所有权，去赋值的丢失其所有权（变成空指针，无法再使用）。

* **unique_ptr**（替代auto_ptr）

  禁止了拷贝语义，提供了移动语义  将所有权从原本的指针转移到新指针

  ```c++
  //将所有权从p1（指向string Stegosaurus）转移给p2
  unique_ptr<string> p2(p1.release());//release将p1置为空
  unique_ptr<string> p3(new string("Trex"));
  //将所有权从p3转移到p2
  p2.reset(p3.release());//reset释放了p2原来指向的内存
  ```

* **shared_ptr**

  可共享指针对象   可以赋值给shared_ptr 或 weak_ptr。

  shared_ptr中所实现的本质是引用计数，拷贝一个shared_ptr将对这个智能指针的引用次数加1，而当这个智能指针的引用次数降低到0次的时候，该对象自动被析构。

  在循环引用中，会出现内存泄露的问题。https://blog.csdn.net/lijinqi1987/article/details/79005738

* **weak_ptr**

  weak_ptr和shared_ptr的最大区别在于weak_ptr在指向一个对象的时候不会增加其引用计数，因此可以用weak_ptr去指向一个对象并且在weak_ptr仍然指向这个对象的时候析构它，此时你再访问weak_ptr的时候，weak_ptr返回的会是一个空的shared_ptr。
  
  用于解决环状引用问题：Weak_ptr允许共享，但不拥有一个对象。 它的对象是由shared_ptr创建的
  
* **区别**：

  unique是独占所指对象的，某一时刻只能有一个unique_ptr指向一个给定对象。

  如果这个对象需要在多个指针之间分享，可以把它转变成shared_ptr。

  如果是unique_ptr，当它被销毁时它所指向的对象也被销毁。 但shared_ptr会维护一个引用计数（use_count），只有最后一个shared_ptr也被销毁时，这个对象才真的被销毁。

* **使用场景**

  不确定使用的指针是不是被分享所有权的时候，默认选unique_ptr独占式所有权，因为unique_ptr效率比shared_ptr高，不需要维护引用计数和背后的控制块。当确定要被分享的时候可以转换成shared_ptr。

  其实只要不涉及多线程的程序，不使用智能指针也没关系。	

  有必要使用shared_ptr的场景：

  ```c++
  //thread1
  void func(shared_ptr<int> p) {...}
  //Main Thread
  shared_ptr<int> p = make_shared<int>();
  func(p);
  
  //主线程开启子线程 并在其中执行func函数  如果不使用智能指针shared_ptr 
  // 当主线程执行完自行释放普通指针p，此时子线程的函数还没执行完，p已经失效了，会造成程序崩溃。
  // 而使用shared_ptr只会在主线程结束时自动将use_count--，不影响子线程的使用。
  ```


### 20. 怎么消除多重继承中的二义性

* 成员限定符
* 虚基类 在继承基类前加virtual
* http://c.biancheng.net/view/2280.html
* 虚继承的目的是让某个类作出声明，承诺愿意共享它的基类，被共享的基类成为虚基类

### 21. 派生新类的三个步骤

* 吸收基类成员
* 改造基类成员
* 添加新成员

### 22. 类的声明和实现的分开的好处

* 起保护作用
* 提高编译的效率

### 23. map与set

* map与set都是基于红黑树（二叉排序树）

### 24. unordered_map 与 unordered_set 

* 两者都是基于hashtable

### 25. #include<filename.h> 和 #include "filename.h"

* 编译器从标准库路径开始搜索

* 编译器从用户的工作路径开始搜索

### 26. static的应用和作用

* 函数体内的static 变量的作用范围为该函数体， 不同于auto变量，该变量的内存只被分配一次，因此其值在下次调用时仍维持上次的值。

* 不想使用全局变量，最好的方式在函数体内使用静态变量。

  ```c++
  void function() {
      int a = 5;
      auto int b = 7;  //a与b 都为自动变量 当funciton被调用时，a和b的值都会压入栈，函数开始执行时，自动变量a和b都与栈内对应的值关联起来，函数调用结束后，栈顶指针回到压栈前的位置。 
  }
  
  //静态变量 有三种形式
  int g_value = 100; //外部链接  静态变量 （其他文件可以访问） extren int g_value
  static int f_value = 200; //内部链接  静态变量 （只在本文件中访问）
  
  void function1() {
      static int in_value = 300; //静态变量  无链接（只能在当前函数或代码块中访问）
  }
  ```

* 模块内的static变量和函数的作用域 只在本模块内

* 类中的static成员变量属于整个类所拥有， 对类的所有对象只有一份拷贝

* 类中的static成员函数属于整个类所拥有， 这个函数不接受this指针， 因而只能访问类的static成员变量。

* 类的static变量在类实例化之前就已经存在了，并且分配了内存。函数的static变量在执行此函数时进行初始化。

  

### 27. stoi函数、to_string函数、atoi函数

* to_string函数 将int、long、double等转化为string

  ```c++
  #include<string>
  int a = 4;
  double b = 3.14;
  string s1 = to_string(a);
  string s2 = to_string(b);
  ```

  

* stoi函数 和 atoi函数将字符串转为int 

  ```c++
  string s1("1234567");
  char* s2 = "1234567";
  int a = stoi(s1);  //stoi 的形参为const string*
  int b = atoi(s2);  //atoi 的形参为const char*
  int c = atoi(s1.c_str()); //c_str()将const string* 转为 const char*
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  ```

### 28. 解决hash冲突的几种方式

* 开放定址法

  1. 线性探测法

     冲突发生的时候，顺序查看表中下一个单元，直到找出一个空闲单元或查遍全表。

     该方法会造成大量元素在相邻的散列地址上聚集，降低了查找的效率。

  2. 平方探测法

     该方法的步长改为了平方数， 避免了堆积问题， 但是无法探测到散列表上的所有单元。

  3. 再散列法

* 拉链法

  把所有同义词都储存在一个线性链表中，适用于经常进行插入和删除的情况。

### 29. 指针，指向指针的指针，野指针，常指针
* **指针**：指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。

  指针变量的类型取决于其指向的数据类型，在所指数据类型前加*

  指针变量的特点是它可以访问所指向的内存。

* **指向指针的指针**：这是一种间接寻址的形式，就是将一个指针的地址存放在另一个指针里面。

  定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的内存位置。

* **野指针**：

  野指针是指向不可用内存区域的指针。野指针不是NULL指针，是指向“垃圾内存”的指针。

  野指针十分危险，因为if无法判断指针是正常指针还是野指针。

  形成的原因：

  **1.  指针变量没有被初始化，指针变量被创建时，不会自动成为null指针，缺省值是随机的。**

  **2. 指针p被free或delete之后，没有置为NULL。这样只会将指针指向的内存给释放掉，并没有把指针本身给清理。**

  ```c++
  char *p = (char *)malloc(10);
  strcpy(p,"hello");
  free(p);  //p所指的内存被释放，变为垃圾内存(不可用内存)，但是p所指的地址没变。
  if(p != NULL)  //没有起到防错作用
  strcpy(p,"world");  //篡改动态内存区，后果难以预料，非常危险
  ```

  **3. 指针操作超越了变量的作用范围。 不要返回指向栈内存的指针或引用， 因为栈内存在函数结束时会被释放。**

  ```c++
  class A {
  public:	
      void Func(void) {}
  };
  void Test(void) {
      A *p;
      {
          A a;
          p = &a; //a存放在栈内存中 生命周期只在这个范围内
      }
      p ->Func();  //a已经被释放  p是野指针
  }
  ```

* **常指针**：

  常指针的含义是指该指针指向的地址不能改变，但该地址所指向的内容可以变化。一般适用于指针不能指向其他变量。

  指向常量的指针 是指该指针指向的地址可以变化， 可以指向其他变量，但是它所指向的内容不能发生改变。

* **函数指针**：

  函数指针是指一个函数入口的指针。

* **指针函数**：

  指针函数是函数的返回值是一个指针类型。

### 30.struct与union的区别

* struct 可以存储多个成员信息， 而union每个成员会用同一个存储空间，只能存储最后一个成员的信息

* 都是由多个不同的数据类型成员组成，在任何时刻，union只存放了一个被先选中的成员，结构体中的所有成员都存在。

* 对union的一个成员赋值，将会对其他成员重写

  ```c++
  struct A {
      int a; //4字节
      char b; //1字节
      shot c; //2字节
  }; //该结构体至少占了7个字节
  union B {
      int a;
      double b; //8字节
      char c;
  }; //分配给union的内存由类型最大的元素size确定
  ```

### 31. 什么是内存对齐

* 对于上述的结构体A的内存空间是8字节 而不是7字节  实际的计算机系统对基本类型数据在内存中存放的位置有限制，会要求这些数据的首地址的值是某个数k（4或8）的倍数，这就是内存对齐。
* 具体细节看https://zhuanlan.zhihu.com/p/30007037

### 32. c++ 11的新特性

* 基于范围的for循环

  ```c++
  int nums[5] = {1,2,3,4,5};
  for(int &num : nums) {
      num *= 2; //数组每个元素倍乘
  }
  ```

* 自动类型推断auto

  当编译器在一个变量声明的时候，能够根据变量赋的值推断该变量的数据类型。

  用auto声明的变量必须初始化

  auto不允许与其他类型组合使用

  函数和模板的参数不能声明为auto

  ```c++
  auto i = 1; // 自动推断i为int
  //定义容器的迭代器
  vector<int> vec(6,10);
  vector<int>::iterator iter = vec.iterator(); //传统方式
  auto iterAuto = vec.iterator(); //使用自动类型推断
  
  //定义在堆上的变量，使用了auto的表达式必须被初始化
  int *p = new auto(0);
  auto *p = new auto(2); 
  auto p = new auto(3); //这个p自动变为了一个int*类型
  ```

* 空指针常量nullptr

  ```c++
  void foo(int n);
  void foo(char* cArr);
  //上面是两个重载函数
  foo(NULL); //调用第一个函数
  foo(nullptr); //调用第二个函数
  ```

* long long int类型

  该类型保证至少是64位的

* 允许sizeof运算符可以在类型数据成员上使用，无需明确对象

  ```c++
  struct p {
      otherClass member;
  };
  sizeof(p::member); //可以直接取类型的某个成员的类型大小
  ```

* 线程支持

  C++11虽然从语言上提供了支持线程的内存模型,但主要的支持还是来自标准库。
  新的标准库提供了一个线程类(std::thread)来运行一个新线程，它带有一个函数对象参数和一系列可选的传递给函数对象的参数。通过std::thread::join()支持的线程连接操作可以让一个线程直到另一个线程执行完毕才停止。std:thread::native_handle()成员函数提供了对底层本地线程对象的可能且合理的平台相关的操作

  

* noexcept 关键字

  noexcept修饰的函数不会抛出异常

  如果在运行时，noexcept函数向外抛出了异常，程序会直接终止，调用terminate()函数，函数内部会调用abort()函数终止程序。

  使用noexcept 可以有效阻止异常的传播与扩散。

  移动构造函数和析构函数 鼓励使用noexcept。


* emplace函数的加入

  emplace_front()对应push_front()函数

  emplace_back()对应push_back()函数

  empalce()对应insert()函数

  这三个函数构造而不是移动或拷贝元素，更好地避免内存的拷贝与移动，使容器插入元素的性能得到进一步提升。

  - 当调用push或insert成员函数时，我们将元素类型的对象传递给它们，这些对象被拷贝到容器中。

  - 而当我们调用一个emplace成员函数时，则是**将参数传递给元素类型的构造函数**。

  - emplace成员使用这些参数在容器管理的内存空间中直接构造元素。

    ```c++
    vector<p> v;
    //使用三个参数的p的构造函数
    v.emplace_back(520, 19, "大忽悠");
    p p1;
    //使用拷贝构造函数（浅拷贝）
    v.emplace_back(p1);
    //使用push_back
    v.push_back(p1);//正确
    //v.push_back(520, 19, "大忽悠");//错误，没有接收三个参数的push_back版本
    //对与push_back的正确做法
    v.push_back(p(520, 19, "大忽悠"));//创建一个临时的p对象传递给push_back 会使用移动构造函数
    ```

    

### 33. STL库

* STL包括三个部分：容器、算法和迭代器。

* 容器分为两部分：序列式容器和关联式容器。

  序列式容器：vector, stack, queue, heap （其内部元素不一定有序，但都可以进行排序）

  关联式容器：set, map, unoreder_set, unoreder_map （内部结构一般是一颗平衡二叉树， 也有哈希表。关联指每个元素都有一个键值和实值，元素按照一定规则存放）

* vector的capacity和size的属性区别

  size 是当前vector容器真实占用的大小。对应方法resize()
  
  capacity是指在发生扩容之前能允许的最大元素空间，即预分配的内存空间。对应方法reserve()
  
*   vector扩容是改变capacity的大小
  
    vector在push_back已成倍增长可以在均摊后达到常数量的事件复杂度，相对于增长指定大小的O(n)时间复杂度更好。
    
    为了防止申请内存的浪费，使用较多的有2倍与1.5倍的增长方式，而1.5倍的增长方式可以更好的实现对内存的重复利用，因为更好。
    
* vector和list的区别

  vector是顺序表，为存储的对象分配了一块连续的地址空间，对元素的随机访问效率高，时间复杂度O(1)。插入与删除需要移动现有元素，比较适合简单的小对象。

  list是循环双链表，当对大量数据进行插入和删除时，时间复杂度O(1)，查找数据需要遍历链表，时间复杂度O(n)。

* 迭代器是一个变量，相当于容器和操纵容器算法之间的中介。迭代器可以指向容器中的某个元素，通过迭代器就可以读写它指定的元素，这一点与指针相似。
  
* vector迭代器的几种失效的情况： 
  1、当插入（push_back）一个元素后，end操作返回的迭代器肯定失效。
  2、当插入(push_back)一个元素后，capacity返回值与没有插入元素之前相比有改变，则需要重新加载整个容器，此时first和end操作返回的迭代器都会失效。
  3、当进行删除操作（erase，pop_back）后，指向删除点的迭代器全部失效；指向删除点后面的元素的迭代器也将全部失效。
  
* pair的使用

  ```c++
  int main()
  {
  	pair<string, int>p;
  	typedef vector< pair<string, int> > VP;
  	VP vp;
  	for (int i = 0; i < 5; i++) {
  		cin >> p.first >> p.second;
  		vp.push_back(make_pair(p.first, p.second));
  	}
  	VP::iterator it;
  	for (it = vp.begin(); it != vp.end(); it++)
  		cout << it->first << "," << it->second << endl;
  	system("pause");
  	return 0;
  }
  ```

  

### 34. sizeof与strlen的区别

* sizeof 是C++的一个运算符，而 strlen 是一个函数（头文件为string.h）；
* sizeof 的操作对象（即操作数operand）可以是数组、指针、类型、对象、函数等，而 strlen 的参数为字符型指针“const char * str”，当数组名作为 strlen 函数参数时，实际上在函数执行时该数组就退化成指针了；
* sizeof 与 strlen 的返回值类型均为 size_t（即 unsigned int）；
* sizeof 的值在编译的时候已经计算好了，而 strlen 是在运行时才计算的。由于是在编译时计算，sizeof 不能用来计算动态分配的内存空间的大小，实际上，使用 sizeof 计算操作数（operand）的大小，其返回值跟操作数存储的内容无关；
* sizeof 对于常见的操作数的计算规则如下：
  数组 -- 编译时为该数组分配的空间大小；
  指针 -- 存储指针所用的空间大小，一般都是固定值，为整型 int 的对应字节数 8；
  类型 -- 指定类型所占的空间大小，如 int 占用8字节、char 占用 1 字节；
  对象 -- 对象实际占用的空间大小；
  函数 -- 函数的返回类型所占的空间大小，如 int 占用8字节。需要注意的是，该函数的返回类型不能是 void。

 ### 35.volatile关键字

* volatile关键字是一种类型修饰符， 用它声明的类型变量表示可以被某些编译器未知的因素更改。比如：操作系统、硬件或者其它线程等。
* 用volatile关键字声明的变量每一次被访问的时候，执行部件都会从变量相应的内存单元中取出变量的值。
* 没有用volatile关键字声明的变量i在被访问的时候可能直接从cpu的寄存器中取值（因为之前i被访问过，也就是说之前就从内存中取出i的值保存到某个寄存器中），之所以直接从寄存器中取值，而不去内存中取值，是因为编译器优化代码的结果（访问cpu寄存器比访问ram快的多）。

### 36.右值引用

* 左值是指表达式结束后依然存在的持久化对象  左值一般在内存中

* 右值是指表达式结束时就不再存在的临时对象  右值一般在内存或CPU寄存器中

* 能对表达式取地址是左值，不能的为右值

  ```c++
  T & ref = lvalue; //左值引用
  T && ref = rvalue; //右值引用
  ```

* 已命名的右值引用，编译器会认为是个左值

### 37. move操作
* 移动构造函数与拷贝构造函数的区别是，拷贝构造函数的参数是const T& t，是常量左值引用

  移动构造函数的参数是T && t，是右值引用。

* 构造函数的参数是个临时对象时，即右值，会优先进入移动构造函数而不是拷贝构造函数。

* 移动构造函数，不会重新分配一块新的内存空间复制拷贝的对象，而是将自己的指针指向别人的资源，然后将别人的指针置为nullptr。这一步十分重要。

* 然而有些左值是局部变量，需要用到移动构造函数。c++11提供了move()方法将左值转换为右值。

* 移动语句https://www.cnblogs.com/chenny7/p/11984699.html

### 38. 指针的各种应用  真的难

* 指针与数组

  指向数组开头的指针，可以通过使用指针的算术运算或数组索引访问数组。

  ```c++
  int var[max] = {10,100,200};
  int *ptr;
  ptr = var;
  *ptr;
  ptr[0]; //都访问第一个元素
  ptr ++;  //到下一个元素
  //把指针运算符*应用到var上是完全可以的，但是修改var的值是非法的。var是一个指向数组开头的常量，不能作为左值。
  var ++;//违法
  *(var+1) = num; //这个是合法的  var的值未改变
  ```

* 指针数组 与 二维数组指针

  ```c++
  int var[MAX]; //数组
  int *ptr[MAX]; //指针数组
  int a[3][4];  //二维数组
  int (*p)[4] = a; //二维数组指针  一个指向有四个整型数组的指针
  *(p+1)+1; //二维数组第一行第一个元素的地址
  *(*(p+1)+1); //二维数组第一行一个元素的值
  for(int i = 0; i < MAX; i ++) {
      ptr[i] = &var[i]; //给每个指针赋上对应数值的地址
  }
  for(int i = 0; i < MAX; i ++) {
      cout << *ptr[i] << endl; //输出var数组每个值
  }
  char a[] = "hello world";
  char *p = a;
  sizeof(a); //12字节
  sizeof(p); //4个字节 或者8个字节  根据系统位数决定
  ```

* 指针函数  和  指向函数的指针

  ```c++
  int *p(); //一个指针函数的声明  返回的也是指针类型
  int (*a)(int); //一个指向函数的指针， 函数有一个整型参数并返回一个整形数
  int (*a[10])(int); //一个有10个指针的数组，这些指针指向一个函数，该函数有一个整型参数并返回一个整型数
  ```
### 39. const和#define

* ```c++
  const int NUM = 100;
  #define NUM 100;
  ```
  
* **类型和安全检查不同**

  宏定义是字符替换，没有数据类型的区别，同时这种替换没有类型安全检查，可能产生边际效应等错误；

  const常量是常量的声明，有类型区别，需要在编译阶段进行类型检查

  **编译器处理不同**

  宏定义是一个"编译时"概念，在预处理阶段展开，不能对宏定义进行调试，生命周期结束与编译时期；

  const常量是一个"运行时"概念，在程序运行使用，类似于一个只读行数据

  **存储方式不同**

  宏定义是直接替换，不会分配内存，存储于程序的代码段中；

  const常量需要进行内存分配，存储于程序的数据段中

  **定义域不同**

  ```c++
void f1()
  {
      #define N 12
      const int n 12;
      
      #undef N //取消宏定义
      #define N 21 //取消可以重新定义
  }
  void f2() 
  {
      cout<<N<<endl; //正确 N不受定义域限制
      cout<<n<<endl; //错误 n定义域只在f1函数中
  }
  ```
  
  **是否可以做函数参数**										

  宏定义不能作为参数传递给函数

  const常量可以在函数的参数列表中出现

* **常量定义规则**

  1. 需要对外公开的常量放在头文件中，不需要对外公开的常量放在定义文件的头部。为便于管理，可以把不同模块的常量集中存放在一个公共的头文件中。

  2. 如果某一常量与其它常量密切相关，应在定义中包含这种关系，而不应给出一些孤立的值。

     ```c++
     const float RADIUS = 100;
     const float DIAMETER = RADIUS * 2;
     ```

* **类中的常量**

  const数据成员只在某个对象生存期内是常量，而对于整个类而言却是可变的，因为类可以创建多个对象，不同的对象其const数据成员的值可以不同。

  const成员变量不能在类中初始化，只能在构造函数中初始化。

  如果想在类中建立恒定的常量，应该使用枚举（enum）

  ```c++
  class A 
  {
      enum
      {
          SIZE1 = 100;
          SIZE2 = 200;
      };
      int arr1[SIZE1];
      int arr2[SIZE2];
  }
  ```

  枚举常量：不会占用对象的存储空间，它们在编译时被全部求值。但其隐含数据类型是整数，其最大值有限，且不能表示浮点数。

### 40. const注意使用

* const 修饰指针变量

  ```c++
  const int *p = 8; // 指向常量的指针 
  int const *p = 8; // 常指针  指针指向的地址不会改变  但是指向的内容会发生改变
  const int const *p = 8; // 指向常量的常指针  指针指向的地址和内容 都不会发生改变
  ```

  ”左定值  右定向  const修饰不变量“

* const参数传递和函数返回值

  值传递一般不需要const修饰  函数会自动产生临时变量复制实参值

  ```c++
  int func(const int a) {}
  int func(int a) {}  //这两个函数是等价的 没有进行函数重载 因为顶层的const参数无法与没有顶层的const参数区分
  
  int func(int& a) {} //函数作用于a的引用
  int func(const int& a) {}  //新函数 函数作用于常量引用
  int func(int* a) {} //新函数  作用于指向a的指针
  int func(const int* a) {} //新函数 作用于指向常量a的指针
  ```

  const 修饰指针和引用 可以防止参数和引用被修改

* const修饰类成员函数

  类成员函数即使没有改变对象的值，编译器也认为函数会改变对象的值，所以不需要改变对象内容的函数都作为const函数。

  ```c++
  void func()const {
      a ++; //错误
      b ++; //正确
  }
  int a;
  mutable int b;  //常类成员函数 要修改某个成员 需要用mutable修饰这个成员

### 42. 外部变量的调用
```c++
x.h
extern int a;//声明其为全局变量
1.cpp
#include "x.h"
int a = 0;//定义变量a,需定义在函数外，否则程序会将其认定为局部变量，同时会将2.cpp中的a认定为未定义的变量，出现链接错误（LINK1120）
void fun（）
{
a = a + 2;
}
2.cpp
#include "x.h"
a = a + 2;//无需定义,a=4
 

关于静态变量（作用域在一个.cpp中，使用时可以全局拷贝，但每个cpp开始使用时变量都从定义时的初始化值开始执行）
在x.h中定义
eg：
x.h
static int a = 0;//定义赋初值并声明为静态变量
1.cpp
#include "x.h"
a = a + 2;//a = 2
2.cpp
#include "x.h"
a = a + 2;//a = 2
```

### 43. 空对象指针

* c++ 空指针是不能使用的  而空对象指针有些时候可以调用成员函数

* 类的成员函数并不与具体对象绑定，一个类的所有对象共用一份成员函数体，程序在编译的时候，成员函数的地址就已经确定。

* 成员函数区分不同的对象，靠的是隐式传递给成员函数的this指针，指向具体对象的this指针。其本质和普通函数是一样的，只是多了一个隐式参数（指向对象的this指针）。

  ```c++
  class A {
  private:
      int num;
  public:
      static void fun1() {
          cout << "fun1" << endl;
      }
      void fun2() {
          cout << "fun2" << endl;
      }
      void fun3() {
          cout << num << endl;
      }
      virtual void fun4() {
          cout << "fun4" << endl;
      }
  }
  
  int main(void) {
      A* ptr = nullptr; //建立空对象指针 不会调用构造函数
      
      ptr -> fun1(); //成功调用  fun1是静态成员函数，只能访问类中的静态成员变量，类中的静态成员变量为整个类所共有，所以调用静态成员函数的时候，不需要传递this指针隐式参数。所以空对象指针可以正常调用静态成员函数。
      ptr -> fun2(); //成功调用 fun2是成员函数，需要传递隐式指针参数，但是函数体内并未使用这个隐式指针 去调用非静态的成员变量 所以空对象指针可以正常调用这个函数。
      ptr -> fun3(); //报错  函数体内需要使用this指针去调用num  但是ptr是空的  ptr ->num 非法 会报错
      ptr -> fun4(); //报错 fun4是虚函数 有虚函数的类会自动生成一个成员变量即虚表指针 调用虚函数的时候 需要使用虚表指针  因为虚表指针是成员变量  所以需要传递隐式指针并使用  而ptr是空的 则会报错
  }
  ```
### 44. STL容器的线程安全性  不是很好理解

* STL容器的线程安全性是

  1. 多个线程读取是安全的：多个线程可以读同一个容器内的数据，读时不允许写操作

  2. 多个线程对不同的容器写入是安全的

 * 如何实现线程安全性

   1. 对于容器成员函数的每一次调用都锁住该容器直到调用完成。

   2. 在容器返回的迭代器生存期结束之前锁住容器

   3. 对于作用于容器的每个算法，在算法执行期间都锁住容器。（实际上这一点毫无必要，因为算法无法识别它们正在操作的容器)

### 45. C++指针大小      

* 指针类型的大小是固定的（无论该指针指向哪种数据类型），在32位系统中为4字节；在64位系统中为8字节。
* 对指针类型的变量进行加减操作时，实际上对该指针变量中保存的地址进行加减操作，具体的变化的数值为指针指向的具体数据类型有关。

### 46. 关联、聚合和组合

* 关联：表示两个类的一般性联系，学生和老师。

* 聚合：相对松散的关系，聚合类不需要对被聚合类负责。

* 组合：关联性强于聚合，组合类与被组合类有相同的生命周期，组合类需要对被组合类负责。

  ```c++
  class A {}
  class B {
      A* a; //聚合
  }
  class C {
      A a; //组合
  }
  ```
### 47._onexit注册一个函数，会在main之后执行

* 使用格式

  ```c++
  int main(void) {
      //存放该类型函数的数据结构为栈
      _onexit(fun1); //必须是int类型返回值且无参的函数  无论放在main中的哪个位置 都是最后执行的
      _onexit(fun2); //且执行的顺序是先进后出的  先执行fun2 再执行fun1
      cout << "end" << endl;
  }
  int fun1() {
      cout << "1" << endl;
      return 0;
  }
  int fun2() {
      cout << "2" << endl;
  }
  ```
### 48.实现一个string类 

```c++
class String {
private:
    char *m_data;  //动态分配内存
public:
    String(const char* str == nullptr); //构造函数 考虑参数为空的情况
    ~String(); //析构函数
    String(const String& other); //为什么拷贝构造函数的参数为引用，这是避免使用拷贝构造死循环。当参数不是引用时，调用拷贝构造函数时形参与实参的结合 会再一次调用拷贝构造函数 进入无尽的循环中。
    String& operator=(const String& other); //拷贝赋值函数
    String(String &&other); //移动构造函数
    String& operator=(String &&other); //移动赋值函数
}; 

String::String(const char* str) {
    if(str == nullptr) {
        m_data = new char[1];
        *m_data = '\0';
    }
    else {
        int len = strlen(str);
        m_data = new char[len+1];
        strcpy(m_data, str);
    }
}

String::~String() {
    delete[] m_data;
}

String::String(const String &other) {
    int len = strlen(other.m_data);
    m_data = new char[len+1];
    strcpy(m_data, other.m_data);
}

String& String::operator=(const String &other) {
    if(this != other) {
        if(!m_data) delete[] m_data;
        int len = strlen(other.m_data);
        m_data = new char[len+1];
        strcpy(m_data, other.data);
    }
    return *this;
}

String::String(String &&other) {
    m_data = other.m_data;
    other.m_data = nullptr;
}

String& String::operator=(String &&other) {
    if(this != &other) {
        if(!m_data) delete[] m_data;
        m_data = other.data;
        other.data = nullptr;
	}
    return *this;
}
```

​	

### 49. 多线程编程

```c++
#include<thread>
using namespace std;

void myFunc() {
    
}

int main() {
    thread tid1;//创建一个线程对象 但是没有相关联的线程
    thread tid2(myFunc); //创建一个线程对象 并传递函数指针
    
    //thread和unique_ptr一样 都不支持赋值操作，支持移动操作
    tid2 = move(tid1); //tid2不再有相关联的执行线程 将线程的所有权转移给了tid1
    
    ------
        
    thread tid1(myFunc);
    thread tid2(myFunc);
    
    //在线程对象析构前，未显示的结合或分离线程，程序就会被终止
    //显示的结合一个线程，主线程中断，等待子线程结束，然后继续向下运行
    tid1.join();
    //显示的分离一个线程，主线程将不等待子线程结束，直接继续向下运行
    tid2.detach();
    
    ------
    
    int a = 10;
    int b = 10;
    thread tid1(myFunc1,a,b);
    thread tid2(myFunc2,&a,ref(b)); //给线程传递引用参数时，需要使用&value或ref(value)显示指出传递的是引用，因为thread是模板类，需要根据传入的实参进行推导形参。
    
    tid1.join();
    tid2.join();
    
    tid2.detach(myFunc,&a,ref(b));//给分离的线程传递自动变量的引用或指针时，要确保在线程执行过程中变量一直有效。
    
}
```



```c++
//线程间访问共享数据
//1.原子操作
atomic<int> num = 0; //atomic模板类创建的变量的操作具有原子性，即不可分割性，仅支持一个线程同时访问
//2.互斥锁 
mutex m; //mutex模板类创建的锁变量 能够对临界区的资源进行加锁 当一个线程抢到了锁 在未解锁之前 其他任何线程都不能加锁这个被锁上的临界区资源
int n = 0;

void func1() {
    num ++:
    m.lock();
    n ++;
    m.unlock();
}
void fun2() {
    num ++;
    m.lock();
    n ++:
    m.unlock();
}

int main(void) {
    thread tid1(func1);
    thread tid2(func2);
    tid1.join();
    tid2.join();
}

//在使用互斥锁的时候，避免互斥锁的相互嵌套，防止发生死锁。
mutex m1;
mutex m2;
int num1 = 0;
int num2 = 0;
int main(void) {
    //tid1和tid2抢占资源 tid1抢占了m1锁 tid2抢占了m2锁  tid1试图对m2加锁 tid2试图对m1加锁 但是m1和m2都处于加锁阶段，就会产生死锁。
    thread tid1([](){
        m1.lock();
        num1 ++;
        m2.lock();
        num2 ++;
        m1.unlock();
        m2.unlock();
    });
    
    thread tid2([](){
        m2.lock();
        num2 ++:
        m1.lock();
        num1 ++:
        m2.unlock();
        m1.unlock();
    });
    
    tid1.join();
    tid2.join();
}
```



### 50. socket编程

网络进程通信使用（ip地址，协议，端口）可以标识网络中的进程。

一般来说，网络进程使用socket通信。

* socket的基本模式：open -> write / read ->close

* 在Linux中socket被认为是文件的一种，在网络传输中可以使用与文件IO相关的函数。两个主机间的通信，实际上是两个socket文件的相互读写。

* socket编程有三种：

  1. sock_stream 流式套接字 

  2. sock_dgram  数据报套接字

  3. sock_raw  原始套接字

基于TCP的socket编程采用sock_stream    

服务器编程的步骤：

1. 加载套接字库，创建套接字， 确定IP类型和套接字类型（socket()）
2. 绑定套接字到一个IP地址和一个端口上（bind()）
3. 将套接字设置为监听模式 等待连接请求（listen()）
4. 请求到来后，接受连接请求，返回一个用于此次连接的套接字（accept()）
5. 用返回的套接字和客户端进行通信（send() / recv() ）
6. 返回，等待另一连接请求
7. 关闭套接字，关闭加载的套接字库

客户端编程的步骤：

1. 加载套接字库，创建套接字
2. 向服务器发出连接请求（connect（））
3. 和服务器端进行通信（send() / recv() ）
4. 关闭套接字，关闭加载的套接字库

### 51. 回调函数

回调函数就是一个通过函数指针调用的函数。将函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用所指向的函数时，这就是回调函数。

```C++
typedef int(*ptr) (int, int);  //使用宏定义的方式 申明一个函数指针

int add(int a, int b, ptr p) { //调用回调函数的函数  加上一个函数指针的参数
    return p(a,b);
}

int callback(int a, int b) { //回调函数 普通的一个函数
    return a + b;
}

int main() {
    int res = add(a, b, callback);
    return 0;
}
```

为什么C++类中的回调函数是静态的：

* 因为回调函数一般是用于解耦的，所以在调用回调函数的类中，并不会有回调函数所属类的对象。而静态成员是属于整个类所有的，所以只能将回调函数定义为静态成员函数，通过类名调用。

### 52. 子类对象调用父类函数

```c++
class Base {
private:
    int val;
public:
    Base(int x) : val(x) {}
    virtual void func1() {
        cout << "Base_v" << endl;
    }
    void func2() {
        cout << "Base_r" << endl;
    }
};

class Drived : public Base {
public:
    Drived(int x) : Base(x) {}
    void func1() {
        cout << "Drived_v" << endl;
    }
    void func2() {
        cout << "Drived_r" << endl;
    }
};

int main() {
    Base base(1);
    Drived drived(2);
    base.func1();
    base.func2();
    drived.func1();
    drived.func2();
    drived.Base::func1();
    drived.Base::func2();  //子类对象调用父类对象的方法 调用结果与是否为虚函数 无关

    Base* p = new Drived(3);  //父类指针指向子类对象
    p ->func1();  //调用子类的虚函数
    p ->func2();  //因为父类没有定义虚函数  则根据指针的指向只会调用父类函数
    p ->Base::func1(); //调用父类的虚函数
    p ->Base::func2(); //调用父类的普通函数 

    return 0;
}
```

### 53. 类的三种权限和三种继承方式

* 访问权限：

  **public** 可以被任意实体访问，可以被外部所查看，对象可以直接调用成员变量

  **protected** 只允许子类（无论子类是何种继承方式）和本类的成员函数访问

  **private** 只允许本类的成员函数访问

  

* 继承方式：  

  **public**继承  不会改变基类成员的访问权限。 派生类可以直接访问父类的public、protected成员

  **protected**继承  将基类成员的public访问权限改为protected，其他访问权限不变。派生类内依旧可以直接访问父类的public、protected成员。

  **private**继承 将基类成员的所有访问权限变为private。 派生类内部依旧可以直接访问父类的public、protected成员。

  

* 派生类**对象**仅当public派生时，才可以直接访问和修改父类的public成员。

### 54. shared_ptr的简单实现

```c++
shared_ptr<T> ptr(new T); //使用shared_ptr对象 托管一个new运算符返回的指针
//ptr可以像T*类型的指针一样使用，即*ptr就是用new动态分配的那个对象
shared_ptr<T> ptr_1 = ptr;
shared_ptr<T> ptr_2 = ptr;
//多个shared_ptr可以共同托管一个指针p,当所有曾经托管p的shared_ptr对象都解除了对其的托管时，就会执行delete p
```

**shared_ptr**类实现：

```c++
template<typename T>
class Shared_ptr {
private:
    T* ptr; //托管对象
    int* count; //引用计数对象
    mutex* pMutex; //互斥锁对象
    
    //释放管理对象
    void release() {
    	bool flag = false;
        
        pMutex ->lock();
        if((*count)-- == 0) {
            delete ptr;
            delete count;
            flag = true;
        }
        pMutex ->unlock();
        
        if(flag == true)delete pMutex;
    }
    
    //增加引用计数
    void addCount() {
        pMutex ->lock();
        (*count) ++;
        pMutex ->unlock();
    }
    
public:
    //构造函数
    Shared_ptr(T* p = nullptr) : ptr(p), count(new int(1)), pMutex(new mutex) {}
    
    //析构函数
    ~Shared_ptr() {
        release();
    }
    
    //拷贝构造函数
    Shared_ptr(const Shared_ptr& s) : ptr(s.ptr), count(s.count), pMutex(s.pMutex) {
        addCount();
    } 
    
    //拷贝赋值函数
    Shared_ptr& operator=(const Shared_ptr& s) {
        if(ptr != s.ptr) {
            release(); //释放掉本身
            
            ptr = s.ptr;
            count = s.count;
            pMutex = s.pMutex;
            
            addCount();
        }
    }
    
    //返回引用计数
    int reCount() {
        return *count;
    }
    
    T* get() {
        return ptr;
    }
    T& operator*() {
        return *ptr;
    }
    T& operator->() {
        return ptr;
    }
}
```

### 55. 友元类和友元函数

* 有些函数不是类的一部分，需要频繁的访问类的数据成员，这时需要将这些函数定义为该类的友元函数。

* 友元的作用是提高了程序的运行效率（减少了类型检查和安全性检查），破坏了类的封装和隐藏

* 友元函数的声明可以放在类的任何部分，不会有区别

* 一个函数可以是多个类的友元函数

**友元类**

当希望一个类可以存取另一个类的私有成员时，可以将该类声明为另一个类的友元类。

```c++
class A {
public:
    friend class B;
}
```

* 友元类不能被继承

* 友元关系是单向的

* 友元关系是不能传递的

  

### 56. 实现一个vec类

```C++
//空间配置器
template<typename T>
struct Myalloc {
    //申请空间
    T* allocator(size_t size) {
        return (T*)malloc(size * sizeof(T));
    }
    //释放空间
    void delallocator(T* p) {
        free(p);
    }
    //调用构造函数
    void counstruct(T* p, const T& val) {
        p = new T(val);
    }
    //调用析构函数
    void destory(T* p) {
        p ->~T();
    }
};

//vec类实现
template<typename T, typename Alloc = Myalloc<T>>
class Vector {
private:
    T* first;
    T* last;
    T* end;
    Alloc alloc;

    //内存扩容
    void expand() {
        size_t len = last - first;
        size_t size = end - first;

        T* temp = alloc.allocator(2*size); //申请两倍的空间
        for(int i = 0; i < len; i ++) alloc.construct(temp + i, first[i]);  //拷贝元素

        des(); //释放原来的内存

        first = temp;
        last = first + len;
        end = first + 2*size;
    }

    //释放内存
    void des() {
        for(T* p = first; p != last; p ++) alloc.destory(p); //析构元素
        alloc.delallocator(first); //释放内存

        first = nullptr;
        last = nullptr;
        end = nullptr;
    }

    //拷贝元素
    void copy(const Vector& vec) {
        size_t len = vec.last - vec.first; //数组长度
        size_t size = vec.end - vec.first; //数组空间大小

        first = alloc.allocator(size); //先申请一样大小的空间
        for(int i = 0; i < len; i ++) alloc.construct(first + i, vec.first[i]); //再调用构造函数

        last = first + len;
        end = first + size;
    }
public:
    //构造函数
    Vector(size_t size = 1) {
        first = alloc.allocator(size); //申请内存空间
        last = first;
        end = first + size;
    }

    //析构函数
    ~Vector() {
        des();
    }

    //拷贝构造函数
    Vector(const Vector& vec) {
        copy(vec);
    }

    //拷贝赋值函数
    Vector& operator=(const Vector& vec) {
        if(*this == vec) return *this;

        if(first != nullptr) {
            des();
        }

        copy(vec);
        return *this;
    }

    bool empty()const {
        return first == last;
    }

    bool full()const {
        return last == end;
    }

    size returnSize()const {
        return last - first;
    }
    //重写中括号
    T& operator[](int index)const {
        if(index >= 0 && index < returnSize()) return first[index];
        return -1;
    }

    //在尾部插入数据
    void push_back(const T& val) {
        if(full()) expand();
        alloc.construct(last, val);
        last ++:
    }

    //在尾部弹出数据
    void pop_back() {
        if(empty()) return;
        last --;
        alloc.destory(last);
    }
};
```

### 57.

