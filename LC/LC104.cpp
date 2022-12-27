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
  public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int l_depth = maxDepth(root->left), r_depth = maxDepth(root->right);
        return max(l_depth, r_depth) + 1;
    }
};

class Solution1 {
    int ans = 0;

    void dfs(TreeNode* node, int cnt) {
        if (node == nullptr)
            return;
        cnt++;
        ans = max(ans, cnt);
        dfs(node->left, cnt);
        dfs(node->right, cnt);
    }

  public:
    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};