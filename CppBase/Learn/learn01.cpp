//
// Created by 23869 on 2022/1/1.
//

#include <stdio.h>


namespace NameSpaceA {
    int a = 0;
}

namespace NameSpaceB {
    int a = 1;
    namespace NameSpaceC {
        struct Teacher {
            char name[10];
            int age;
        };
    }
}

int main(void) {
    using namespace NameSpaceA;
    using NameSpaceB::NameSpaceC::Teacher;

    printf("a=%d\n", a);//0
    printf("a=%d\n", NameSpaceB::a);//1

    NameSpaceB::NameSpaceC::Teacher t2;
    Teacher t1 = {"aaa", 13};

    printf("t1.name=%s\n", t1.name);
    printf("t1.age=%d\n", t1.age);
    return 0;

}

