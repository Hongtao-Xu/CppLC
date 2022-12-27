#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //边界条件
        if (p == nullptr || q == nullptr)
            return p == q; //只有两个都为空才返回true
        return p->val == q->val && isSameTree(p->left, q->right) &&
               isSameTree(p->right, q->left);
    }

  public:
    bool isSymmetric(TreeNode* root) {
        //根节点相同，只要判断左右子树是否相同即可
        return isSameTree(root->left, root->right);
    }
};