#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = root->val;
        //1.p,q都在左子树，返回左子树递归结果
        if (p->val < x && q->val < x)
            return lowestCommonAncestor(root->left, p, q);
        //2.p,q都在右子树，返回右子树递归结果
        if (p->val > x && q->val > x)
            return lowestCommonAncestor(root->right, p, q);
        //3.p,q分别在左右子树 || 当前节点是p || 当前节点是q , 返回当前节点
        return root;
    }
};