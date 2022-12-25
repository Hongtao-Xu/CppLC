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
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next && cur->next->next) { //下个节点和下下个节点必须存在
            int val = cur->next->val; //下个节点的值
            if (val == cur->next->next->val)
                while (cur->next &&cur->next->val == val) { //循环删除所有此数字节点
                    cur->next = cur->next->next;
                }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};