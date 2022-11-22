#include <bits/stdc++.h>


using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
  public:
    int sumSubseqWidths(vector<int>& nums) {
        //排序
        sort(nums.begin(), nums.end());
        int n = nums.size(), pow2[n];
        pow2[0] = 1; // 2^0=1
        for (int i = 1; i < n; i++)
            pow2[i] = pow2[i - 1] * 2 % MOD; //预处理2的幂次
        long ans = 0L;
        for (int i = 0; i < n; i++)
            ans += long(pow2[i] - pow2[n - 1 - i]) * nums[i];
        return (ans % MOD + MOD) % MOD; //上面有减，ans可能为负数
    }
};