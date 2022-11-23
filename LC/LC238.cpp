//
// 238. 除自身以外数组的乘积
//
#include<vector>
#include<iostream>

using namespace std;

//左右乘积列表，空间换时间
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = nums.size();
        vector<int> L(len);//i左边的数乘积和
        vector<int> R(len);//i右边的数乘积和
        vector<int> res(len);
        L[0] = 1, R[len - 1] = 1;
        for (int i = 1; i < len; i++) {
            L[i] = nums[i - 1] * L[i - 1];
        }
        for (int i = len - 2; i >= 0; --i) {
            R[i] = nums[i + 1] * R[i + 1];
        }
        for (int i = 0; i < len; i++) {
            res[i] = L[i] * R[i];
        }
        return res;
    }
};

//不适用额外空间
class Solution1 {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = nums.size();

        vector<int> res(len);
        res[0] = 1;
        //左到右
        for (int i = 1; i < len; ++i) {
            res[i] = nums[i - 1] * res[i - 1];
        }
        //右到左
        int R = 1;
        for (int i = len - 1; i >= 0; --i) {
            res[i] = res[i] * R;
            R *= nums[i];
        }
        return res;
    }
};

int main() {
    vector<int> num = {4, 5, 1, 8, 2};
    Solution s;
    vector<int> res = s.productExceptSelf(num);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}