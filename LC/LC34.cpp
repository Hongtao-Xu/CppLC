#include <bits/stdc++.h>

using namespace std;

class Solution {
    //闭区间写法：
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; //[left,right]
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left; //或right+1
    }

  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};
