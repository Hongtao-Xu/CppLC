#include<bits/stdc++.h>
using namespace std;


class Solution {
	public:
		bool splitArraySameAverage(vector<int>& nums) {
			int n=nums.size(),m=n/2;
			//无法分为2个数组
			if (n==1)
				return false;
			//(start,end,init,option)
			int sum=accumulate(nums.begin(),nums.end(),0);
			//nums中的每个数字*n-sum/n = 整数
			for(int &x :nums)
				x=x*n-sum;
			
			unordered_set<int> left;
			for(int i=1;i<(1<<m);i++){// 2^(n/2)种分法
				int tot=0;
				for(int j=0;j<m;j++){
					if(i&(1<<j)){//
						tot+=nums[j];
					}
				}
				if(tot==0)
					return true;
				left.emplace(tot);
			}
			int rsum=accumulate(nums.begin()+m,nums.end(),0);
			for(int i=1;i<(1<<(n-m));i++){
				int tot=0;
				for(int j=m;j<n;j++){
					if(i&(1<<(j-m))){//
						tot+=nums[j];
					}
				}
				if(tot==0||(rsum!=tot&&left.count(-tot)))
					return true;
				
			}
			return false;
		}
};


