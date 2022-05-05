//const限定符
#include<iostream>
#include"const.h"			//辅助头文件
using namespace std;

int main() {

	//**1.const对象必须初始化
	const int n1 = 42;	//正确


//**2.默认状态下，const对象仅在文件内有效
	extern const int bufsiz;	//想要使用外部的const对象，需要在定义前加上extern
	const int bufsiz = 512;		//一旦先前加上extern，后面定义的同名对象将不起作用
	cout << bufsiz << endl;		//输出1024


//**3.const对象的简单引用
	const int n2 = 888;		//const对象
	const int& n2_ptr1 = n2;	//const引用绑定常量对象,正确

	int n3 = 999;			//普通对象
	const int& n3_ptr1 = n3;	//const引用绑定普通对象,即不能通过n3_ptr1修改n3的值,正确

	//const int c = 666;		//const对象
	//int& ci = c;			//不能将普通引用绑定const引用，错误。

	//****NOTE: 临时量
	double d1 = 3.14;
	const int& d1_ptr = d1;		//编译器将生成一个临时变量：const int tmp = dval;

	//double dval = 3.14;
	//int& d = dval;		//错误,此种语法希望通过d来修改dval的值，实际修改的是它的临时量，所以不行。


//**4.指针和const
	//口诀: 左指右本
	//const在*的左边，代表该指针指向一个const对象
	//const在*的右边，代表该指针本身是个const指针

	const double d2 = 3.14;		//const对象
	//double* d2_ptr = &d2;		//错误，普通指针不能指向const对象
	const double* d2_ptr = &d2;	//正确，该指针可以指向const对象

	double d3 = 3.8;		//普通对象
	const double* d3_ptr = &d3;	//正确，但不能使用该指针来修改d3的指
	//const int* d3_ptr = &d3;	//错误，不存在临时量，这点和引用不同

	//tip:所有指向常量的指针或引用，它们很自以为是，都自以为指向的是个常量，所以它们不愿意修改所指向的对象。
	int n4 = 2020;
	const int* n4_ptr = &n4;


	//**5.顶层const 与 底层const
	int n5 = 100;
	int* const n5_ptr1 = &n5;	//顶层const表示这个指针本身是const，即本身不可被修改。(右本)
	const int* n5_ptr2 = &n5;	//底层const表示它所指向的对象不可通过该指针修改。(左指)
	const int& n5_r = n5;		//NOTE:用于声明引用的const是底层const。
	//拷贝操作规律:可以忽视顶层const，但遭到底层const限制
	//当右值为底层const时，左指也必须为底层const。(右底左必底)

	const int n6 = 200;
	const int* n6_ptr = &n6;
	//int* const n6_ptr = &n6;
	//int* tmp = n6_ptr;		//错误:左边不是底层const，而右边是
	int n7 = 400;
	int* n7_ptr1 = &n7;
	const int* n7_ptr2 = n7_ptr1;	//正确:右边不是底层const，不影响

	//总结:右底左必底


//**6.constexpr常量
	const int n8 = 800;		//n8是个常量表达式
	constexpr int n9 = n8;		//右值必须是个常量表达式
	//int n10 = 10;
	//const n11 = n10		//正确
	//constexpr int n11 = n10;	//错误,右值不是常量表达式

	//constexpr sz = get_sz()	//此时get_sz()函数必须是constexpr函数
}
