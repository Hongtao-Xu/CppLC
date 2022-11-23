#include<iostream>
//二级指针
using namespace std;

struct Teacher {
    char name[64];
    int age;
};

//在被调?函数 获取资源
int getTeacher(Teacher **p) {
    Teacher *tmp = NULL;
    if (p == NULL) {
        return -1;
    }
    //tmp:指针，指向开辟出来的Teacher空间
    tmp = (Teacher *) malloc(sizeof(Teacher));
    if (tmp == NULL) {
        return -2;
    }
    tmp->age = 33;//通过指针修改值

    //p是实参的地址		*实参的地址 去间接的修改实参的值
    *p = tmp;//指针（赋值给）指针
    return 0;
}

//指针的引? 做函数参数
int getTeacher2(Teacher* &myp) {
    //给myp赋值 相当于给main函数中的pT1赋值
    myp = (Teacher *) malloc(sizeof(Teacher));
    if (myp == NULL) {
        return -1;
    }
    myp->age = 36;
    return 0;
}

void FreeTeacher(Teacher *pT1) {
    if (pT1 == NULL) {
        return;
    }
    free(pT1);
}

int main(void) {
    Teacher *pT1 = NULL;
    //1	c语?中的?级指针
    getTeacher(&pT1);
    cout << "age:" << pT1->age << endl;
    FreeTeacher(pT1);

    //2	c++中的引? （指针的引?）
    //引?的本质 间接赋值后2个条件 让c++编译器帮我们程序员做了。
    getTeacher2(pT1);
    cout << "age:" << pT1->age << endl;
    FreeTeacher(pT1);
    return 0;
}