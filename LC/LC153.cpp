
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int findMin(vector<int>& nums) {
        // 1.一段递增或两段递增
        // 2.nums[1]>nums[end]
        // 3.最后一个数：最小值或最小值右侧
        // 4.[0,n-2]如果：mid <nums[end]:最小值在左侧
        //          如果：mid >nums[end]:最小值在右侧
        int left = -1, right = nums.size() - 1, end = right;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[end]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return nums[right];
    }
};