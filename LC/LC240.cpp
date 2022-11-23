//
// 240. 搜索二维矩阵 II
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1.直接遍历
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        //for(auto x : range) // 拷贝元素
        //for(auto &&x : range)// 修改元素
        //for(const auto &x : range)// 只读元素（无法修改）
        for (const auto &row: matrix) {//&原地读取和修改
            for (int element: row) {
                if (element == target)
                    return true;
            }
        }
        return false;
    }
};

//2.二分查找
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for (const auto &row: matrix) {
            //大于等于target的第一个值,查不到返回row.end()
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target)
                return true;
        }
        return false;
    }
};

//Z 字形查找
class Solution2 {
public:

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();//m:行，n:列
        int x = 0,y=n-1;
        while (x < m && y >= 0) {
            if (matrix[x][y]==target)
                return true;
            if (matrix[x][y]>target)
                y--;
            else if (matrix[x][y]<target)
                x++;
        }
        return false;
    }
};