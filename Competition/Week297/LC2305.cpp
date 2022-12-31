#include <bits/stdc++.h>
#include <vector>

using namespace std;

//解法一：暴搜 DFS
class Solution {
  public:
    //全局变量
    int ans = 1e9; //当前最小值，8*10^5
    int sum[8] = {0};
    vector<int> q;
    int k;

    void dfs(int u) {
        if (u == q.size()) {
            int mx = 0;
            for (int i = 0; i < k; ++i)
                mx = max(mx, sum[i]); //此种方案下，所有组中的最大值
            ans = min(ans, mx);       //更新答案
            return;
        }
        for (int i = 0; i < k; ++i) {
            sum[i] += q[u];
            //减枝：sum[i]>=ans,不可能优化最优解
            if (sum[i] < ans)
                dfs(u + 1);
            sum[i] -= q[u];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        q = cookies;
        this->k = k;
        dfs(0);
        return ans;
    }
};

//解法二：子集状压DP
class Solution1 {
  public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> sum(1 << n); //一共有状态

        // sum预处理，(sum为集合的元素和)
        for (int i = 0; i < n; ++i)
            for (int j = 0, bit = 1 << i; j < bit; ++j)
                sum[bit | j] = sum[j] + cookies[i];

        //二进制数来表示集合，其第 i 位为 1 表示分配了第 i 块饼干，
        //                           为 0 表示未分配第 i 块饼干

        vector<int> f(sum); // copy
        //倒序枚举 j，f 的第一个维度可以省略
        for (int i = 1; i < k; ++i) {
            for (int j = (1 << n) - 1; j; --j) {
                for(int s = j;s;s=(s-1)&j)
                    f[j]=min(f[j],max(f[j^s],sum[s]));
            }
        }
        return f.back();
    }
};