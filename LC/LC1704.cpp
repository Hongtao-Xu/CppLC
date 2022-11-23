//
// Created by 23869 on 2022/11/11.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool halvesAreAlike(string s) {
        string a = s.substr(0, s.size() / 2);
        string b = s.substr(s.size() / 2);
        string h = "aeiouAEIOU";
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (h.find_first_of(a[i]) != string::npos)//string::npos 表示不存在的位置
                sum1++;
        }
        for (int j = 0; j < b.size(); ++j) {
            if (h.find_first_of(b[j]) != string::npos)
                sum2++;
        }
        return sum1 == sum2;
    }
};