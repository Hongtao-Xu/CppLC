#include <bits/stdc++.h>

using namespace std;

/*
以数字1,数字2,数字3,数字4“结尾”的最长递增子序列的长度与个数取并-->  [1,2,3,4]
                                                                /     \
以数字1,数字2“结尾”的最长递增子序列的长度与个数取并--------->    [1,2] [3,4]
                                                             /   \      /   \
                                                         [1,1] [2,2] [3,3] [4,4]
                                                                /        \
以数字1“结尾”的最长递增子序列的长度与个数
以数字2“结尾”的最长递增子序列的长度与个数 自底向上merge
*/

struct SegTree {
    int left, right;
    SegTree *lchild, *rchild;
    pair<int, int> len_count;
    SegTree(int l, int r)
        : left(l), right(r), lchild(nullptr), rchild(nullptr),len_count(0, 1){};
};

class Solution {
  public:

    pair<int, int> merge(pair<int, int> len_count1, pair<int, int> len_count2) {
        if (len_count1.first == len_count2.first) {
            if (len_count1.first == 0) {
                return {0, 1};
            }
            return {len_count1.first, len_count1.second + len_count2.second};
        }
        return len_count1.first > len_count2.first ? len_count1 : len_count2;
    }
    
    void insert(SegTree* root, int key, pair<int, int>& len_count) {
        int mid = root->left + (root->right - root->left) / 2;
        if (root->left == root->right) {
            root->len_count = merge(len_count, root->len_count);
            return;
        } else if (key <= mid) {
            if (!root->lchild)
                root->lchild = new SegTree(root->left, mid);
            insert(root->lchild, key, len_count);
        } else {
            if (!root->rchild)
                root->rchild = new SegTree(mid + 1, root->right);
            insert(root->rchild, key, len_count);
        }
        if (root->lchild && root->rchild) {
            root->len_count =
                merge(root->lchild->len_count, root->rchild->len_count);
        } else if (root->lchild && !root->rchild) {
            root->len_count = root->lchild->len_count;
        } else if (!root->lchild && root->rchild) {
            root->len_count = root->rchild->len_count;
        }
    }

    pair<int, int> query(SegTree* root, int key) {
        if (key >= root->right)
            return root->len_count;
        else if (key < root->left)
            return {0, 1};
        else {
            if (!root->lchild && !root->rchild) {
                return {0, 1};
            } else if (!root->lchild && root->rchild) {
                return query(root->rchild, key);
            } else if (root->lchild && !root->rchild) {
                return query(root->lchild, key);
            } else {
                return merge(query(root->lchild, key),
                             query(root->rchild, key));
            }
        }
    }
    int findNumberOfLIS(vector<int>& nums) {
        int min_v = *min_element(nums.begin(), nums.end());
        int max_v = *max_element(nums.begin(), nums.end());
        SegTree* root = new SegTree(min_v, max_v);
        // cout<<root->len_count.second<<endl;
        for (auto num : nums) {
            pair<int, int> len_count = query(root, num - 1);
            ++len_count.first;
            // cout<<len_count.second<<endl;
            insert(root, num, len_count);
        }
        return root->len_count.second;
    }
};
