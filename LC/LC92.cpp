#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 如果left=1的情况，解决p0的指向问题
        ListNode *dummy = new ListNode(0, head), *p0 = dummy;
        for (int i = 0; i < left - 1; i++)
            p0 = p0->next;
        // p0指向要反转的节点的前一个节点

        ListNode *pre = nullptr, *cur = p0->next;
        for (int i = 0; i < right - left + 1;i++) { //需要处理的节点个数为：right-left+1
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        //处理反转部分的头尾
        p0->next->next = cur;//p0->next = 原来要反转的头节点
        p0->next = pre;
        return dummy->next;
    }
};