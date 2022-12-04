#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0, area = 0;
        while (left < right) {
            area = (right - left) * min(height[left], height[right]);
            ans = max(ans, area);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};