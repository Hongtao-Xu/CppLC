#include<iostream>

using namespace std;

int getA1() {
    int a;
    a = 10;
    return a;
}

int &getA2() {
    static int a;
    a = 10;
    return a;
}

int main(void) {
    int a1 = 1;
    int a2 = 2;
    //值拷?
    a1 = getA1();
    //将?个引?赋给?个变量，会有拷?动作
    //理解： 编译器类似做了如下隐藏操作，a2	=	*(getA2())
    a2 = getA2();
    //将?个引?赋给另?个引?作为初始值，由于是栈的引?，内存?法
    int &a3 = getA2();
    cout << "a1	=	" << a1 << endl;
    cout << "a2	=	" << a2 << endl;
    cout << "a3	=	" << a3 << endl;
    return 0;
}

