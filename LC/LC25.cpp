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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //计算链表长度
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        ListNode *dummy = new ListNode(0, head), *p0 = dummy;
        ListNode *pre = nullptr, *curr = head;
        while (n>=k) {//剩余节点还可以反转
            n-=k;

            for(int i=0;i<k;i++){
                ListNode *nxt = curr->next;
                curr->next=pre;
                pre=curr;
                curr=nxt;
            }
            
            ListNode*nxt = p0->next;//维护p0

            p0->next->next=curr;
            p0->next=pre;
            
            p0=nxt;//维护p0
        }
        return dummy->next;
    }
};