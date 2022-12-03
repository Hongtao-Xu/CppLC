#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    //相向双指针
    //答案三元组顺序不重要：i<j<k
    //答案不可包含重复三元组：跳过相同数字
    vector<vector<int>> threeSum(vector<int>& nums) {
        //排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int x = nums[i];
            if (i > 0 && x == nums[i - 1]) //处理重复元素
                continue;
            //优化：由于nums已经是有序的，可以排除不可能情况
            if (x + nums[i + 1] + nums[i + 2] > 0)
                break;
            if (x + nums[n - 1] + nums[n - 2] < 0)
                continue;
            int j = i + 1, k = n - 1; // j和k一前一后，往中间靠
            //这里变为了两数之和问题
            while (j < k) {
                int s = x + nums[j] + nums[k];
                if (s > 0) {
                    k--;
                } else if (s < 0) {
                    j++;
                } else { //找到s==0了
                    ans.push_back({x, nums[j], nums[k]});
                    j++; //维护j
                    while (j < k && nums[j] == nums[j - 1]) //处理重复元素
                        j++;
                    k--; //维护k
                    while (k > j && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};