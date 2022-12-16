#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//解法一：重建链表
class Solution {
  public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode*> vec;
        ListNode* node = head;
        while (node != nullptr) {
            vec.emplace_back(node);
            node = node->next;
        }
        //重建
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j)
                break;
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};

//解法二：反转
class Solution1 {
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        //快指针指向空，或下一个节点指向空，slow为中间节点
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

  public:
    void reorderList(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* head2 = reverseList(mid);
        while (head2->next) {
            //记录两个next
            ListNode* nxt = head->next;
            ListNode* nxt2 = head2->next;
            //连接
            head->next = head2;
            head2->next = nxt;
            //移动
            head = nxt;
            head2 = nxt2;
        }
    }
};
