#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

//解法一:哈希表
class Solution {
  public:
    char repeatedCharacter(string s) {
        unordered_set<char> seen;
        for (char ch : s) {
            if (seen.count(ch))
                return ch;
            seen.insert(ch);
        }
        return ' ';
    }
};

//解法二: 状态压缩
class Solution1 {
  public:
    char repeatedCharacter(string s) {
        int seen = 0;
        for (char ch : s) {
            int x = ch - 'a';
            if (seen & (1 << x))
                return ch;
            seen |= (1 << x);
        }
        return ' ';
    }
};