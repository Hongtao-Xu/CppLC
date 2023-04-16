#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Interval {
  public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class SegmentTree {
  public:
    SegmentTree *left, *right;
    int start, end, min;
    SegmentTree(int start, int end, int min = 0)
        : left(NULL), right(NULL), start(start), end(end), min(min){};

    static SegmentTree* build(int start, int end, vector<int>& nums) {
        //特判
        if (start > end)
            return NULL;
        SegmentTree* root = new SegmentTree(start, end, nums[start]);
        if (start == end)
            return root;

        // root一定有子线段树
        int mid = start + ((end - start) >> 1);
        root->left = build(start, mid, nums);
        root->right = build(mid + 1, end, nums);
        // min的维护
        if (root->left != NULL) root->min = std::min(root->min, root->left->min);
        if (root->right != NULL)root->min = std::min(root->min, root->right->min);
        return root;
    }

    static int queryMin(SegmentTree *node,int start,int end){
        if (start <= node->start &&  node->end <= end) {
            return node->min;
        }
        int mid = node->start + ((node->end - node->start) >> 1);
        int leftRet = INT_MAX, rightRet = INT_MAX;
        //查询区间[start,end]与左子区间node.left[node.start,mid]有交集
        if (start <= mid) leftRet = queryMin(node->left, start, end);
        //查询区间[start,end]与右子区间node.right[mid+1,node.end]有交集
        if (end >= mid + 1) rightRet = queryMin(node->right, start, end);
        return std::min(leftRet, rightRet);
    }
};

class Solution {
  public:
    vector<int> intervalMinNumber(vector<int>& a, vector<Interval>& queries) {
        SegmentTree * root = SegmentTree::build(0, a.size()-1, a);
        vector<int> result;

        for (int i = 0; i < queries.size(); ++i)
            result.push_back(SegmentTree::queryMin(root, queries[i].start, queries[i].end));

        return result;
    }
};