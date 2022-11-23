//
// Created by 23869 on 2022/11/10.
//

#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numberEvenListNode(ListNode *head) {
        int ans = 0;
        while (head != nullptr) {
            //偶数：+0
            //奇数：+1
            ans += head->val % 2;
            head = head->next;
        }
        return ans;
    }
};