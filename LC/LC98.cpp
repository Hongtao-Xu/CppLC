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

//方法一：前序遍历---> 先判断，再递归
class Solution {
  public:
    bool isValidBST(TreeNode* root, long left = LONG_MIN,
                    long right = LONG_MAX) {
        if (root == nullptr)
            return true;
        long x = root->val;
        return left < x && x < right && isValidBST(root->left, left, x) &&
               isValidBST(root->right, x, right);
    }
};

//方法二：中序遍历---> 大于上一个节点
class Solution2 {
    long pre = LONG_MIN;

  public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        //左子树不是BST || 未大于上一个节点(BST中序遍历严格递增)
        if (!isValidBST(root->left) || root->val <= pre)
            return false;
        pre = root->val;
        return isValidBST(root->right);
    }
};

//方法三：后序遍历---> 先递归，再判断
class Solution3 {
    // root.val-->[l_min,r_max]
    pair<long, long> dfs(TreeNode* node) {
        if (node == nullptr)
            return {LONG_MAX, LONG_MIN}; //是BST
        auto [l_min, l_max] = dfs(node->left);
        auto [r_min, r_max] = dfs(node->right);
        long x = node->val;
        //判断当前节点值是否: 不符合范围
        // BST应满足性质：root值>左子树最大值，root值<右子树最小值
        if (x <= l_max || x >= r_min)
            return {LONG_MIN, LONG_MAX}; //不是BST
        return {min(l_min, x), max(r_max, x)};
    }

  public:
    bool isValidBST(TreeNode* root) { return dfs(root).second != LONG_MAX; }
};