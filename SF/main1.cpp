//
// Created by 23869 on 2022/11/6.
//

#include <bits/stdc++.h>

using namespace std;

//最长连续公共子序列 LCS
//https://blog.csdn.net/JamSlade/article/details/120683339

int main() {
    string A, B;
    cin >> A >> B;
    int lenA = A.length(), lenB = B.length();
    //int a[][4]={{1,2,3,4},{5,6,7,8}};
    //int b[2][]={{1},{2}};
    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1));
    int res = 0;
    for (int i = 0; i < lenA; ++i) {
        for (int j = 0; j < lenB; ++j) {
            //前一个位置相同，递推式为：dp[i-1][j-1]+1
            if (A[i] == B[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                res = max(res, dp[i + 1][j + 1]);
            }
            //前一个位置相同，从0开始累加
        }
    }
    cout << "Result:" << res << endl;
}

int main1() {
    //未初始化，二维数组中的值是随机的
    int a[3][4];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "================" << endl;

    vector<vector<int>> dp(3, vector<int>(4));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}