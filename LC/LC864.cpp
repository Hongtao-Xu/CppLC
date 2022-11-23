//
// Created by 23869 on 2022/11/11.
//

#include <bits/stdc++.h>

using namespace std;

//BFS+状态压缩(位运算)
class Solution {
public:
    int shortestPathAllKeys(vector<string> &grid) {
        /*
            '.'： 代表一个空房间
            '#'： 代表一堵
            '@'： 是起点
            小写字母：代表钥匙
            大写字母：代表锁
         */
        int m = grid.size(), n = grid[0].size();
        int sx = 0, sy = 0;//起点位置
        unordered_map<char, int> key_to_idx;//当前的钥匙是第几把钥匙char就是钥匙的字母,int就是第几把钥匙
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {//寻找起点
                    sx = i;
                    sy = j;
                } else if (islower(grid[i][j])) {//钥匙
                    //"a钥匙的数量"不为0
                    if (!key_to_idx.count(grid[i][j])) {
                        // [a钥匙:a钥匙是第几把钥匙]
                        int idx = key_to_idx.size();
                        key_to_idx[grid[i][j]] = idx;
                    }
                }
            }
        }
        //tuple(3个以上): 泛化的std::pair
        //pair: 是2个成员
        queue<tuple<int, int, int>> q;
        //dist = [m,n,k=2^钥匙数量]
        //k:表示当前位置的钥匙状态使用二进制表示,数组中存储的数据就是当前状态的最小步数
        //将所有的最小步数首先初始化为-1表示没有被访问过
        vector<vector<vector<int>>> dist(m,
                                         vector<vector<int>>(n,
                                                             vector<int>(1 << key_to_idx.size(), -1)));
        //起点插入：q=[sx,sy,0]
        q.emplace(sx, sy, 0);
        dist[sx][sy][0] = 0;//设置步数为0
        while (!q.empty()) {
            auto [x, y, mask] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {//4个方向
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != '#') {
                    if (grid[nx][ny] == '.' || grid[nx][ny] == '@') {//1.空房间或者起点
                        if (dist[nx][ny][mask] == -1) {//当前位置未被访问
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;//步数+1
                            q.emplace(nx, ny, mask);
                        }
                    } else if (islower(grid[nx][ny])) {//2.钥匙
                        int idx = key_to_idx[grid[nx][ny]];//获取钥匙的编号（就是二进制中代表当前钥匙的1的位置）
                        //如果当前位置在获取到对应钥匙之后没有被走过
                        if (dist[nx][ny][mask | (1 << idx)] == -1) {
                            dist[nx][ny][mask | (1 << idx)] = dist[x][y][mask] + 1;//步数+1
                            //如果发现钥匙已经全部获取完了就直接退出,返回当前位置的最小步数
                            if ((mask | (1 << idx)) == (1 << key_to_idx.size()) - 1) {
                                return dist[nx][ny][mask | (1 << idx)];
                            }
                            //钥匙没有获取完,将当前的钥匙标记为已获取并入队
                            q.emplace(nx, ny, mask | (1 << idx));
                        }
                    } else {//3.锁
                        //获取锁对应钥匙的二进制位
                        int idx = key_to_idx[tolower(grid[nx][ny])];
                        //如果当前位置获取到了锁对应的钥匙,且获取到该锁的钥匙之后没有走过就更新
                        if ((mask & (1 << idx)) && (dist[nx][ny][mask] == -1)) {
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
                    }
                }
            }
        }
        return -1;
    }

private:
    static constexpr int dirs[4][2] = {{-1, 0},
                                       {1,  0},
                                       {0,  -1},
                                       {0,  1}};
};
