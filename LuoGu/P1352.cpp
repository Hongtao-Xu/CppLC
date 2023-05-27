#include <bits/stdc++.h>
using namespace std;
#define MAXN 6005

int h[MAXN];           //每个员工的快乐指数
int v[MAXN];           //辅助找到校长
vector<int> son[MAXN]; //员工上下级关系
int f[MAXN][2];

void dp(int x) {
    //初始化f[x][0/1]
    f[x][0] = 0;
    f[x][1] = h[x];
    //遍历x的子节点
    for (int i = 0; i < son[x].size(); i++) {
        int y = son[x][i]; // y是x的下级
        dp(y);
        f[x][0] += max(f[y][0], f[y][1]); // x不参加, max(y参加/不参加)
        f[x][1] += f[y][0];               // x参加,y不能参加
    }
}

int main() {
    int n;
    cin >> n;
    // why for loop start with 1: 1<= x,y <=n
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        son[y].push_back(x); // y领导的员工有x
        v[x] = 1;
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            root = i; //如何根据{x:y}知道谁是校长：只有校长没有上级
            break;
        }
    }
    dp(root);
    cout << max(f[root][0], f[root][1]) << endl; //校长来或不来
    return 0;
}