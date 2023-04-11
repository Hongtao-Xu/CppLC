#include <bits/stdc++.h>
#include <vector>

using namespace std;

// 1.暴力BFS
class Solution {

    using Node = tuple<int, int, int>;
    const int kInf = 0x3f3f3f3f;

  public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dis(m, vector<int>(n, kInf)); // mxn的矩阵
        queue<Node> q;
        q.emplace(1, 0, 0); //队列存储(d,x,y)
        dis[0][0] = 1;      //在原点，占一个格子

        while (!q.empty()) {
            auto [d, x, y] = q.front();
            q.pop();
            if (x == m - 1 && y == n - 1) //已经到达终点，返回格子数d
                return d;

            int g = grid[x][y];

            //===倒序===
            //向右走
            for (int ny = min(n - 1, g + y); ny > y; --ny) {
                if (dis[x][y] + 1 < dis[x][ny]) {
                    dis[x][ny] = dis[x][y] + 1; //类型单调栈
                    q.emplace(d + 1, x, ny);
                }
            }
            //向下走
            for (int nx = min(m - 1, g + x); nx > x; --nx) {
                if (dis[x][y] + 1 < dis[nx][y]) {
                    dis[nx][y] = dis[x][y] + 1; //类型单调栈
                    q.emplace(d + 1, nx, y);
                }
            }
        }
        return -1; // BFS结束，无法到达，返回-1
    }
};

/**
思路：应该跳过访问过的节点
关键：如何快速找到一个节点的下一个未访问可达节点？
实现：
访问到一个节点时，将该节点的 fa 指针指向相邻的下一个节点，
这样下次访问到这个节点时，可以跳到下一个未访问的节点
*/

// 2.BFS+并查集
class Solution1 {

    using Node = tuple<int, int, int>;

    auto find(vector<int>& fa, int x) -> int {
        return x == fa[x] ? x : fa[x] = find(fa, fa[x]); //x == fa[x]，找到根节点
    }

    void merge(vector<int>& fa, int x){
        fa[x] = x+1;
    }

  public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> row_fas(m, vector<int>(n+1)); // m x n+1 的矩阵
        for(int i=0;i<m;++i)
            iota(row_fas[i].begin(),row_fas[i].end(),0);//从0开始自增

        vector<vector<int>> col_fas(n, vector<int>(m+1)); // n x m+1 的矩阵
        for(int j=0;j<n;++j)
            iota(col_fas[j].begin(),col_fas[j].end(),0);//从0开始自增    


        queue<Node> q;
        q.emplace(1, 0, 0); //队列存储(d,x,y)

        while (!q.empty()) {
            auto [d, x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1) //已经到达终点，返回格子数d
                return d;

            int g = grid[x][y];

            //===倒序===
            //向右走
            for(int ny = find(row_fas[x],y+1);ny <n&& ny<=g+y; ny=find(row_fas[x], ny+1)){
                merge(row_fas[x],ny);
                q.emplace(d+1,x,ny);
            }
            //向下走
            for(int nx = find(col_fas[y],x+1);nx <m&& nx<=g+x; nx=find(col_fas[y], nx+1)){
                merge(col_fas[y],nx);
                q.emplace(d+1,nx,y);
            }
        }
        return -1; // BFS结束，无法到达，返回-1
    }
};