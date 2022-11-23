#include<bits/stdc++.h>

using namespace std;

class Solution {
	public:
		//是否存在j>i+1,使得nums[i]>nums[j]成立
		//转化为：nums[i]>min(nums[i+2],...,nums[n-1])是否成立
		bool isIdealPermutation(vector<int>& nums) {
			//一次遍历,倒序
			int n = nums.size(), minSuff = nums[n - 1];
			for (int i = n - 3; i >= 0; i--) {
				if (nums[i] > minSuff) {
					return false;
				}
				//minSuff: [1,n-1]
				minSuff = min(minSuff, nums[i + 1]);
			}
			return true;
		}
};
