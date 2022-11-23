
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Solution {
  public:
    bool is_blue(vector<int>& nums, int index, int target) {
        int end = nums[nums.size() - 1];
        if (nums[index] > end) { // index在上一段
            return (target > end) && (nums[index] >= target);
        } else { // index在下一段
            return (target > end) || (nums[index] >= target);
        }
    }
    int search(vector<int>& nums, int target) {
        //闭区间:[0,n-1]
        //开区间:[-1,n]
        int left = -1, right = nums.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (is_blue(nums, mid, target)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        //特判：
        if ((right == nums.size()) || (nums[right] != target))
            return -1;
        return right;
    }
};