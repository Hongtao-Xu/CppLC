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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) //有重复节点，删除
                cur->next = cur->next->next;
            else //无重复节点，往下走
                cur = cur->next;
        }
        return head;
    }
};