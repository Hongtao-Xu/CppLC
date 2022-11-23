#include    <iostream>
//常指针
using namespace std;
struct Teacher {
    char name[64];
    int age;
};

void printTeacher(const Teacher &myt) {
    //常引? 让 实参变量 拥有只读属性
//     myt.age	=	33;//无法修改
    printf("myt.age:%d \n", myt.age);

}

int main(void) {
    Teacher t1;
    t1.age = 36;
    printTeacher(t1);
    return 0;
}