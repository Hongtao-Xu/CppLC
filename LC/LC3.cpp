#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left = 0, right = 0;
        // hashmap：记录字符出现次数
        unordered_map<char, int> cnt;
        while (right < s.length()) {
            cnt[s[right]] += 1;
            while (cnt[s[right]] > 1) { // cnt[c]=1只允许出现一次，无重复
                cnt[s[left]] -= 1;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};