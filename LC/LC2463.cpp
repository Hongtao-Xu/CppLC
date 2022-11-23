//
// Created by 23869 on 2022/11/7.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //factory[位置，容量]
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
        //排序：robot和factory都排序的时候结果最优，（可以用相邻交换法证明）
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(), [](auto &a, auto &b) { return a[0] < b[0]; });
        int m = robot.size();
        //0-1背包空间由二维优化为一维
        //+1是为了方便处理0的情况
        long f[m + 1];
        memset(f, 0x3f, sizeof(f));
        //f[i][j] 表示前 i 个工厂修复前 j 个机器人的最小移动总距离
        f[0] = 0;
        for (auto &fa: factory) {
            for (int j = m; j > 0; --j) {//从后往前遍历机器人，避免覆盖
                long cost = 0l;
                for (int k = 1; k <= min(j, fa[1]); ++k) {//第j个工厂修了 k 个机器人
                    cost += abs(robot[j - k] - fa[0]);//j-k:是因为倒序j
                    f[j] = min(f[j], f[j - k] + cost);//min(一个不修，修k个)
                }
            }
        }
        return f[m];
    }
};