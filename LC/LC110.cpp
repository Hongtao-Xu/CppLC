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
    int get_height(TreeNode* node) {
        if (node == nullptr)return 0;
        int lHeight = get_height(node->left);
        if (lHeight == -1)return -1;
        int rHeight = get_height(node->right);
        if (rHeight == -1)return -1;
        if (abs(lHeight - rHeight) > 1)return -1;
        return max(lHeight, rHeight) + 1;
    }

  public:
    bool isBalanced(TreeNode* root) {
        return get_height(root) != -1; //-1不平衡
    }
};