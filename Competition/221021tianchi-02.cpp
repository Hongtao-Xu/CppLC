//
// Created by 23869 on 2022/11/10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //方向顺序：上下左右
    int dirs[4][2] = {{-1, 0},
                      {1,  0},
                      {0,  -1},
                      {0,  1}};

    int getLength(vector<string> &grid) {
        //L:把方向 ^2
        //R:把方向 ^3
        int n = grid.size(), m = grid[0].length();
        int ans = 0, x = 0, y = 0;//起始坐标：(x,y)=(0,0)
        int d = 1;
        while ((0 <= x && x < n) && (0 <= y && y < m)) {
            ans += 1;
            if (grid[x][y] == 'L')
                d ^= 2;//异或2
            else if (grid[x][y] == 'R')
                d ^= 3;
            x += dirs[d][0], y += dirs[d][1];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> g;
    g.push_back("...");
    g.push_back("RR.");
    g.push_back("L.R");
    int ans = s.getLength(g);
    cout << ans << endl;
}