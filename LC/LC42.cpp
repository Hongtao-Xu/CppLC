#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

//解法一：
//时间复杂度：O(n)
//空间复杂度：O(n)
class Solution {
  public:
    int trap(vector<int>& height) {
        int n = height.size(), pre_max[n], suf_max[n], ans = 0;
        //最大前缀
        pre_max[0] = height[0];
        for (int i = 1; i < n; i++)
            pre_max[i] = max(pre_max[i - 1], height[i]);
        //最大后缀
        suf_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf_max[i] = max(suf_max[i + 1], height[i]);
        //计算接的水
        for (int i = 0; i < n; i++)
            ans += min(pre_max[i], suf_max[i]) - height[i];
        return ans;
    }
};

//解法二：
//时间复杂度：O(n)
//空间复杂度：O(1)
class Solution1 {
  public:
    int trap(vector<int>& height) {
        int ans = 0, left = 0, right = height.size() - 1, pre_max = 0,
            suf_max = 0;

        while (left <= right) { //当left==right时，也有一格在接水
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            if (pre_max < suf_max) {
                ans += pre_max - height[left];
                left++;
            } else {
                ans += suf_max - height[right];
                right--;
            }
        }

        return ans;
    }
};