#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    //相向双指针
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1, s = 0;
        while (true) { //或者left<right
            s = numbers[left] + numbers[right];
            if (s == target)
                break;
            if (s > target)
                right--;
            else
                left++;
        }
        return {left + 1, right + 1};
    }
};