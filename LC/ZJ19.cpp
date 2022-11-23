#include <iostream>
#include <vector>

using namespace std;

//组合公式：从n个元素中选取两个进行组合
long long C(long long n) {
    return (n - 1) * n / 2;
}

int main() {
    int N, D;
    cin >> N >> D;
    long long count = 0;
    vector<int> res(N);
    for (int end = 0, begin = 0; end < N; ++end) {
        cin >> res[end];
        while (end >= 2 && (res[end] - res[begin]) > D) {
            begin++;//不满足begin往前移动
        }


        count += C(end - begin);//由于判断一次往前移动（for循环中的end++），即可以采用每次固定首位的组合。
    }
    cout << count % 99997867;
}

