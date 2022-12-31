#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 12, M = 1 << 10, K = 110;

/* 题目描述：
  nxn的棋盘上放了k个国王(可攻击8个方向)
  数据范围：n：[1,10]
           k：[0,n^2]
*/
int n, m;
vector<int> state;
vector<int> cnt(M,0);//状态state[a]的国王个数
vector<int> head[M]; // head[i]数组里存储在第i行状态为state[a]的情况下，上一行状态可以取到的合法状态state[b]
LL f[N][K][M];       // f[i][j][s]所有只摆了前i行，已经摆了j个国王并且第i行摆放状态是s的所有方案集合

// 检查state这一行是否满足条件
bool check(int state) {
    for (int i = 0; i < n; i++)
        if ((state >> i & 1) && (state >> (i + 1) & 1)) //同一行两个国王不能相邻
            return false;
    return true;
}
// 统计state这一行的国王数量
int count(int state){
    int res =0;
    for(int i=0;i<n;++i) res+=state>>i&1;
    return res;
}

int main() {
    cin >> n >> m;
    //预处理所有合法状态(一行可能的所有合法状态)
    for (int i = 0; i < 1 << n; ++i)
        if (check(i)) {
            state.push_back(i); //将合法方案存入state
            cnt[i] = count(i);
        }
    //预处理所有合法状态的合法转移
    for (int i =0;i<state.size();++i)
        for(int j=0;j<state.size();++j)
        {
            int a = state[i],b = state[j];
            if((a&b)==0&&check(a|b))//a & b 指第i行和i-1行不能在同列有国王,check(a|b)指i和i-1行不能相互攻击到
                head[i].push_back(j);//head[i]里存储在第i行状态为state[a]的情况下，上一行状态可以取到的合法状态statep[b]
        }
    f[0][0][0]=1;//初始方案需要为1,因为全部空 也是一种方案
    for(int i=1;i<=n+1;++i)//枚举每一行
        for(int j=0;j<=m;++j)//枚举国王数量
            for(int a = 0;a<state.size();++a)//枚举合法方案
                for(int b:head[a]){
                    int c = cnt[state[a]];//状态为state[a]的国王个数
                    if(j>=c)
                        f[i][j][state[a]]+=f[i-1][j-c][state[b]];
                        //因为state[a]和a呈映射关系，所也可以写成
                        //f[i][j][a] += f[i - 1][j - c][b];
                }
    cout << f[n + 1][m][0] << endl;//我们假设摆到n + 1行，并且另这一行状态为0,那么即得到我们想要的答案， 
}
