//
// C++的优化：引用
//
#include <iostream>

using namespace std;

//交换的案例：
//c的解决方法
void myswap1(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//c++的解决方法
void myswap2(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//结构体打印：
struct Student {
    char name[64];
    int id;
};

void printS1(struct Student s) {//Student s = s1;值拷贝，整个结构体拷贝，效率较低
    cout << s.id << " " << s.name << endl;
}

void printS2(struct Student *sp) {//Student &s=s1; 取地址，也会浪费效率
    cout << sp->id << " " << sp->name << endl;
}

void printS3(struct Student &sp) {
    cout << sp.id << " " << sp.name << endl;
}

int main(void) {
    int a = 10;
    int b = 20;
//    myswap1(&a, &b);
//    myswap2(a, b);
//    cout << "a=" << a << endl;
//    cout << "b=" << b << endl;
    Student student = {"xiaohu", 223};
    printS1(student);
    printS2(&student);
    printS3(student);
}


