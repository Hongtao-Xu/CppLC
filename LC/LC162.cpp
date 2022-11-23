
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int findPeakElement(vector<int>& nums) {
        //闭区间：[0,n-2]
        //开区间：(-1,n-1)
        int left = -1, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid; //目标峰顶左侧
            } else {
                right = mid; //目标峰顶及其右侧
            }
        }
        return right;
    }
};