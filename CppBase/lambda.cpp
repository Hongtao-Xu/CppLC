#include<bits/stdc++.h>

using namespace std;

int main() {
	vector<int> vec {0, 4, 6, 2, 4, 8, 9, 23, 54, 667};
	auto f = [](int a, int b) {
		return a < b;
	};
	//排序
	sort(vec.begin(), vec.end(), f);

	int N = 100, M = 10;
	//入参：支持auto
	//可以省略 ->int ，可以通过return自动推断返回值类型
	auto g = [N, &M,K=5](auto i) {
		M = 20; //可以修改外部变量，按引用捕获
		//N=10; //无法修改，按值捕获
		cout<<"K:"<<K<<endl;
		return N * i;
	};
	//[&]:按引用捕获所有变量
	//[=]:按值  捕获所有变量
	cout << g(10) << endl;
	cout << "M:" << M << endl;
	cout << "N:" << N << endl;
}
