#include <bits/stdc++.h>
#include <cctype>

using namespace std;

//解法一：stringStream分割
class Solution {
  public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        vector<string> tokens;
        string temp;
        while (ss >> temp) {
            tokens.push_back(temp);
        }
        int preNum = -1;
        int curNum;
        for (int i = 0; i < tokens.size(); ++i) {
            stringstream isDigital(tokens[i]);
            if (isDigital >> curNum) {
                if (curNum <= preNum)
                    return false;
                preNum = curNum;
            }
        }
        return true;
    }
};

//解法二：直接遍历
class Solution1 {
  public:
    bool areNumbersAscending(string s) {
        int pre = 0, pos = 0;
        while (pos < s.size()) {
            if (isdigit(s[pos])) {
                int cur = 0;
                while (pos < s.size() && isdigit(s[pos])) {
                    cur = cur * 10 + s[pos] - '0';
                    ++pos;
                }
                if (cur <= pre)
                    return false;
                pre = cur;
            } else
                ++pos;
        }
        return true;
    }
};

int main() {
    string str = "hello world 5 x 5";
    Solution s;
    s.areNumbersAscending(str);
}