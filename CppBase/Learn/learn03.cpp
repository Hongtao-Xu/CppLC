//
// c++语言的增强
//
#include <iostream>

using namespace std;

void test1() {
    int i = 0;
    cout << "i = " << i << endl;

    int k = 4;
    cout << "k = " << k << endl;
};

/*
 * //重复定义检测
int	g_var;
int	g_var	=	1;
*/

//结构体变量的优化
struct Student {
    char name[64];
    int id;
};

int main(void) {
    Student st1 = {"xiaom", 233};
    //struct Student st1 = {"xiaom", 233};
    cout << st1.name << endl;
}


