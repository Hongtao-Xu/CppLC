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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *right = dummy, *left = dummy;
        // right走n步
        while (n--) {
            right = right->next;
        }
        // right - left = n
        while (right->next) {
            left = left->next;
            right = right->next;
        }
        // left: 倒数第n+1个节点，right:最后一个节点
        left->next = left->next->next;
        return dummy->next;
    }
};