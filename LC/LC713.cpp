#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;
        int ans = 0, prod = 1, left = 0, right = 0;
        while (right < nums.size()) {
            int x = nums[right];
            prod *= x;
            while (prod >= k) {
                prod /= nums[left++];
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};