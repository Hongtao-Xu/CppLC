#include <bits/stdc++.h>

using namespace std;

class Solution {
    // Dijkstra 算法模板
    // 返回从 start 到每个点的最短路
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int start) {
        // g的结构：
        //[ [{u,v},{u,v}..]
        //  [{u,v},{u,v}..]..]
        vector<int> dist(g.size(), INT_MAX);
        dist[start] = 0; // start到start的距离为0
        // Type:存储的数据类型
        // Container: 要比较的基础容器类型
        // Compare: 比较器
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, start); // emplace:容器中原地创建对象;push:创建临时对象，拷贝；
        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            if (d > dist[x])
                continue; //剪枝
            for (auto [y, wt] : g[x]) {
                int new_d = dist[x] + wt;
                if (new_d < dist[y]) {
                    dist[y] = new_d;
                    pq.emplace(new_d, y);
                }
            }
        }
        return dist;
    }

  public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> g(n); // g的容量大小为n
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            //建图
            g[u].emplace_back(v, cnt + 1);
            g[v].emplace_back(u, cnt + 1);
        }
        auto dist = dijkstra(g, 0); //从0出发的最短路径
        int ans = 0;
        for (int d : dist) {
            if (d <= maxMoves) //此点可以在maxMoves内到达
                ans++;
        }
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = max(maxMoves - dist[u], 0);
            int b = max(maxMoves - dist[v], 0);
            ans += min(a + b, cnt); //这条边上可以到达的节点数
        }
        return ans;
    }
};