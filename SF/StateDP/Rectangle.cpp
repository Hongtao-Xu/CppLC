#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long LL;
//先放横着的，再放竖着的
const int N=12,M=1<<N;//N表示行数，M表示列的方案数

int n,m;
LL f[N][M];
vector<int> state[M];//存储所有合法状态
vector<bool> st(M);  //存储每种状态是否有奇数个连续的0，如果是奇数个0是无效状态，如果是偶数个0置为true

/*
    求把 N×M 的棋盘分割成若干个 1×2 的长方形，有多少种方案
    输入：     输出：
    1 2         1
    1 3         0
    1 4         1
    2 2         2
    2 3         3
    2 4         5
    2 11        144
    4 11        51205
    0 0
*/

int main(){
    while (cin>>n>>m,n||m) {//多个输入
        //1. 对于每种状态，先预处理每列不能有奇数个0 
        for(int i=0;i<1<<n;++i){//预处理st数组,判断所有连续的0是否有偶数个
            int cnt = 0;//表示0的个数
            bool isValid = true;//是否合法 
            for(int j=0;j<n;++j)//遍历这一列，从上到下
                if(i>>j&1){//对于i的二进制数的第j位,判断是否为1
                    if(cnt&1){//判断前面的0是否有奇数个
                        isValid = false;//不合法 
			 		    break;
                    }
                    cnt=0;//清空
                }else {
                    ++cnt;//否则前面是0，cnt++ 
                }
            if(cnt&1) isValid=false;//判断最下面那一段连续0的个数
            st[i] = isValid;
        }

        //2. 判断第i - 2列伸出来的和第i - 1列伸出去的是否冲突
	    for(int j = 0;j < 1 << n;++j){//对于第i列的所有状态
            state[j].clear();//清空上次操作遗留的状态(因为本题有while循环，多个测试数据)
            for(int k=0;k<1<<n;++k){//对于第i-1列的所有状态
                if((j & k)==0 && st[j | k])//（i列和i-1列无重叠）&&（每列不能有奇数个0）
				    state[j].push_back(k);//j | k表示当前第i- 1列到底有几个1，即哪几行是放格子的 
            }   
        }

        //3.枚举
        memset(f,0,sizeof f);//全部初始化为0，因为是while连续读入
        f[0][0] = 1;//这里没有-1列，所以不可能有方块伸到第0列，因此f[0][0] = 1, 即表示棋盘为空的一种状态 

        for(int i =1;i <= m;i ++)//遍历每一列:第i列合法范围是(0~m-1列)
            for(int j = 0;j < 1 << n;j ++)//遍历当前列（i）的所有状态j 
                for(auto k: state[j])//遍历第i-1列的状态k,真正满足则转移
                    f[i][j] += f[i - 1][k];// 当前列的方案数就等于之前的第i-1列所有状态k的累加。
    cout << f[m][0] << endl; //依据状态表示的定义:f[m][0]表示 前m-1列都处理完，并且第m-1列没有伸出来的所有方案数。
    }
    return 0;
}