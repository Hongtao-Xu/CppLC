//
// 236. 二叉树的最近公共祖先
//

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dfs
class Solution {
  public:
    TreeNode* ans;

    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr)
            return false;
        bool Lson = dfs(node->left, p, q);
        bool Rson = dfs(node->right, p, q);
        //找到公共祖先
        if ((Lson && Rson) || ((node->val == p->val && (Lson || Rson)) ||
                               (node->val == q->val && ((Lson || Rson))))) {
            ans = node;
        }
        //有可能有
        return (Lson || Rson) || (node->val == p->val || node->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};

//存储父节点
class Solution1 {
  public:
    //{[val,TreeNode],...}
    map<int, TreeNode*> fa;
    //{[val,bool],...}
    map<int, bool> vis;

    void dfs(TreeNode* node) {
        if (node->left != nullptr) {
            fa[node->left->val] = node;
            dfs(node->left);
        }
        if (node->right != nullptr) {
            fa[node->right->val] = node;
            dfs(node->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa[root->val] = nullptr; //根节点的父节点为null
        dfs(root);
        //先走一遍p
        while (p != nullptr) {
            vis[p->val] = true;
            p = fa[p->val];
        }
        //再走q
        while (q != nullptr) {
            if (vis[q->val])
                return q; // q节点就是结果
            q = fa[q->val];
        }
        return nullptr;
    }
};

//灵佬：分类讨论
class Solution2 {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 1.当前节点空 || 当前节点是p || 当前节点q，返回当前节点
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 2.左右子树都找到，返回当前节点
        if (left && right)
            return root;
        // 3.左右子树都找不到，返回空
        if (!left && !right)
            return nullptr;
        // 4.只有左子树或只有右子树找到，返回左或右子树递归结果
        return left ? left : right;
    }
};