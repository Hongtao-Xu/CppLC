#include <bits/stdc++.h>

using namespace std;

//暴力法
// class MajorityChecker {
//     int n, a[20005];

//   public:
//     MajorityChecker(vector<int>& arr) {
//         n = arr.size();
//         for (int i = 0; i < n; i++)
//             a[i] = arr[i]; // a[i]等价于arr
//     }

//     // i:游标；j:众数；k:众数的次数
//     int query(int left, int right, int threshold) {
//         //摩尔投票算法
//         //寻找众数j
//         int i, j, k;
//         j = k = 0;
//         for (i = left; i <= right; i++) {
//             if (a[i] == j) {
//                 k++;
//             } else if (k) {
//                 k--;
//             } else {
//                 j = a[i];
//                 k = 1;
//             }
//         }
//         // j已经是众数了，统计众数的次数
//         for (i = left, k = 0; i <= right; i++) {
//             if (a[i] == j)
//                 k++;
//         }
//         if (k < threshold)
//             j = -1;
//         return j;
//     }
// };

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
//线段树
class MajorityChecker {
    struct node {
        int x, cnt;
        node operator+(const node& b) const {
            node t;
            if (x == b.x) {
                t.x = b.x;
                t.cnt = cnt + b.cnt;
            } else if (cnt < b.cnt) {
                t.x = b.x;
                t.cnt = b.cnt - cnt;
            } else {
                t.x = x;
                t.cnt = cnt - b.cnt;
            }
            return t;
        }
    } t[65536];
    int n, a[20005];
    vector<int> s[20005];

    void build(int R, int l, int r) {
        if (l == r) {
            t[R].x = a[l];
            t[R].cnt = 1;
            return;
        }
        // R<<1: R*2;     R<<1|1: R*2+2
        int mid = l + r >> 1;
        build(R << 1, l, mid);
        build(R << 1 | 1, mid + 1, r);
        t[R] = t[R << 1] + t[R << 1 | 1];
    }
    node ask(int R, int l, int r, int l1, int r1) {
        if (l1 == l && r == r1)
            return t[R];
        int mid = l + r >> 1;
        if (r1 <= mid)
            return ask(R << 1, l, mid, l1, r1);
        if (l1 > mid)
            return ask(R << 1 | 1, mid + 1, r, l1, r1);
        return ask(R << 1, l, mid, l1, mid) +
               ask(R << 1 | 1, mid + 1, r, mid + 1, r1);
    }

  public:
    MajorityChecker(vector<int>& arr) {
        n = arr.size();
        for (int i = 0; i < n; i++)
            s[a[i] = arr[i]].emplace_back(i);
        build(1, 0, n - 1);
    }

    int query(int left, int right, int threshold) {
        int ans = ask(1, 0, n - 1, left, right).x;
        if (upper_bound(s[ans].begin(), s[ans].end(), right) -
                lower_bound(s[ans].begin(), s[ans].end(), left) <
            threshold)
            ans = -1;
        return ans;
    }
};