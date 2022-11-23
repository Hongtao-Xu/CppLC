#include<bits/stdc++.h>
using namespace std;

// NC78 反转链表

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
	public:
		ListNode* ReverseList(ListNode* pHead) {
			struct ListNode* prev = NULL;
			struct ListNode* curr = pHead;
			struct ListNode* next = NULL;
			while (curr != NULL) {
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			return prev;
		}
};

