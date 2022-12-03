#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        if (n == 0)
            return 0;
        int start = 0, end = 0, res = INT_MAX, sum = 0;
        //移动右指针
        while (end < n) {
            sum += nums[end];
            //闭区间：[start,end]
            while (sum >= target) {//移动左指针
                res = min(res, end - start + 1);
                sum -= nums[start++];
            }
            end++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
int main(){
    Solution s;
    vector<int> nums = {2,3,1,2,4,3};
    s.minSubArrayLen(7, nums);
}