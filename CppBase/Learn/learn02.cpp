#include <iostream>

//方式二：
//using std::cout;
//using std::endl;

//方式三：
using namespace std;

int main(void) {
#if 0
    //方式一：
    std::cout<<"hello  world"<<std::endl;
    std::cout<<"hello world2"<<std::endl;
#endif
    //cout<<"hello world"<<std::endl;
    int a = 0;
    cin >> a;
    cout << "a=" << a << endl;
}

