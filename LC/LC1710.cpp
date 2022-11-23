#include<bits/stdc++.h>

using namespace std;


class Solution {
	public:
		int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
			//传递 vector<int> a 时,函数得到向量的一个副本,有一个拷贝操作
			//传递 vector<int> &a 时,获得引用，函数中的任何变化都会修改原始数据
			//const vector<int> &a
			sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a,const vector<int> &b) {
				return a[1] > b[1];
			});
			int res = 0;
			for (auto &bt : boxTypes) {
				int numberOfBoxes = bt[0];
				int numberOfUnitsPerBox = bt[1];
				//这个盒子还可以全部选取
				if (numberOfBoxes < truckSize) {
					res += numberOfBoxes * numberOfUnitsPerBox;
					truckSize -= numberOfBoxes;
				} else { //这个盒子无法全部选取
					res += truckSize * numberOfUnitsPerBox;
					break;//卡车已满
				}
			}
			return res;
		}
};
