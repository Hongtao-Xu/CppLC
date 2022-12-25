#include <bits/stdc++.h>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        //复制下一个节点值到当前节点
        node->val=node->next->val;
        //删除下一个节点
        node->next=node->next->next;
    }
};