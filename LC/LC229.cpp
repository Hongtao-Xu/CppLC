#include <bits/stdc++.h>
#include <vector>

using namespace std;

//摩尔投票算法
/**
    在一个数组中出现次数大于n/3的数最多有2个 ==> 四个变量
    题目未说明保证存在满足条件的数 ==> 增加验证环节
*/
class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int can1 = 0, can2 = 0;
        for (int num : nums) {
            if (can1 == num)
                ++cnt1;
            else if (can2 == num)
                ++cnt2;
            // candidate和cnt的判断不能交换顺序，否则可能为两个候选值赋为同一个值
            else if (cnt1 == 0) {
                can1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                can2 = num;
                cnt2 = 1;
            } else {
                --cnt1;
                --cnt2;
            }
        }
        //验证是否满足条件
        vector<int> res;
        cnt1 = 0, cnt2 = 0;
        for (int num : nums) {
            if (can1 == num)
                ++cnt1;
            //注意一定要用else
            //if，保证两数的判断是有先后的，才不会出现两候选数相同的情况
            else if (can2 == num)
                ++cnt2;
        }
        if (cnt1 > nums.size() / 3)
            res.emplace_back(can1);
        if (cnt2 > nums.size() / 3)
            res.emplace_back(can2);
        return res;
    }
};