#include <iostream>
#include <vector>

//用C＋＋的标准名字空间
using namespace std;

int main() {
    // 1.一维数组访问
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 0, 0};
    // 推荐方式
//    for (int index = 0; index < 10; ++index)
//    	cout << a[index] << " ";
//    cout << endl;
    // 不推荐方式
//    for (int index = 0; index <= 9; ++index)
//    	cout << a[index] << " ";

      // 2.二维数组访问
//    int a[2][4] = {{1, 2, 3, 4},
//                   {5, 6, 7, 8}};
//    for (int row = 0; row < 2; ++row) {
//        for (int col = 0; col < 4; ++col)
//            cout << a[row][col] << "";
//    }
//    cout << endl;

    // 3.动态数组vector
    //创建动态数组vector
    vector<int> vec = { 1,2,3,4 };
    cout << "size is " << vec.size() << endl;
    cout << "capacity is " << vec.capacity() << endl;
    // 遍历所有元素
    for (int index = 0; index < vec.size(); ++index)
    {
        cout << vec[index] << endl;
    }
    // 在尾部插入一个元素5
    vec.push_back(5);
    cout << "size is " << vec.size() << endl;
    cout << "capacity is " << vec.capacity() << endl;
    // 遍历所有元素
    for (int index = 0; index < vec.size(); ++index)
    {
        cout << vec[index] << endl;
    }
    // 在中间插入一个元素6
    vec.insert(--vec.end(), 6);
    cout << "size is " << vec.size() << endl;
    cout << "capacity is " << vec.capacity() << endl;
    // 遍历所有元素
    for (int index = 0; index < vec.size(); ++index)
    {
        cout << vec[index] << endl;
    }
    // 在尾部移除一个元素
    vec.pop_back();
    cout << "size is " << vec.size() << endl;
    cout << "capacity is " << vec.capacity() << endl;
    // 遍历所有元素
    for (int index = 0; index < vec.size(); ++index)
    {
        cout << vec[index] << endl;
    }

    // 在任意位置移除一个元素
    vec.erase(vec.end() - 2);
    cout << "size is " << vec.size() << endl;
    cout << "capacity is " << vec.capacity() << endl;
    // 遍历所有元素
    for (int index = 0; index < vec.size(); ++index)
    {
        cout << vec[index] << endl;
    }
    return 0;
}