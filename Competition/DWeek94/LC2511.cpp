#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int captureForts(vector<int>& forts) {
        //对每个 1，向左向右找 −1，且中间的必须都是 0
        int ans = 0, j = 0;
        for (int i = 0; i < forts.size(); i++) {
            if (forts[i] != 1)continue;
            //往左
            for (j = i - 1; j >= 0 && forts[j] == 0; --j);
            if (j >= 0 && forts[j] == -1)ans = max(ans, i - j - 1); //(j,i)
            //往右
            for (j = i + 1; j < forts.size() && forts[j] == 0; ++j);
            if (j < forts.size() && forts[j] == -1)ans = max(ans, j - i - 1); //(i,j)
        }
        return ans;
    }
};