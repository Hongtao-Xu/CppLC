#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast==slow) {//指针相遇，此时在环的入口处
                while (slow!=head) {
                    slow=slow->next;
                    head=head->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};