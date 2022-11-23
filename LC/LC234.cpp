#include <vector>
#include <iostream>

using namespace std;

/*
 * 234. 回文链表
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//复制数组，双指针
class Solution1 {
public:
    bool isPalindrome(ListNode *head) {
        vector<int> val;
        while (head != nullptr) {
            val.push_back(head->val);
            val.emplace_back();

            head = head->next;
        }
        for (int i = 0, j = val.size() - 1; i < j; ++i, --j) {
            if (val[i] != val[j])
                return false;
        }
        return true;
    }
};

//递归
class Solution2 {
    ListNode *frontPointer;
public:
    bool recursiveCheck(ListNode *currentNode) {
        if (currentNode != nullptr) {
            //递归
            if (!recursiveCheck(currentNode->next)) {
                return false;
            }
            if (frontPointer->val != currentNode->val) {
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }

    bool isPalindrome(ListNode *head) {
        frontPointer = head;
        return recursiveCheck(head);
    }
};

//不适用额外空间
class Solution3 {
public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr)
            return true;

        ListNode *firstHalfEnd = endOfFirstHalf(head);
        ListNode *secondHalfStart = reverseList(firstHalfEnd->next);

        //判断是否回文。
        ListNode *p1 = head;
        ListNode *p2 = secondHalfStart;
        bool result = true;
        while (result && p2 != nullptr) {
            if (p1->val != p2->val) {
                result = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        //恢复链表。
        firstHalfEnd->next = reverseList(secondHalfStart);
        //返回结果。
        return result;
    }

    //找到前半部分链表的尾节点。
    ListNode *endOfFirstHalf(ListNode *node) {
        ListNode *slow = node;
        ListNode *fast = node;
        //第一个条件是必须的，特例：【1】，fast.next.next会指向未知，报错
        while (fast->next != nullptr && fast->next->next != nullptr) {
//        while (fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //反转后半部分链表。
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }

};

int main() {
//    ListNode *pre = new ListNode();
//    ListNode *p =pre;
//    for (int i = 1; i <= 2; ++i) {
//        pre->next = new ListNode(i);
//        pre = pre->next;
//    }
//    Solution3 s;
//    bool res = s.isPalindrome(p->next);
//    cout << res;

}