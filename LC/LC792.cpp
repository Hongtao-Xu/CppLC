#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int numMatchingSubseq(string s, vector<string>& words) {
			vector<queue<pair<int, int>>> q(26);
			//初始化，存入words的首字符
			for (int i = 0; i < words.size(); i++) {
				//入队i,j指针，(i:word在words中位置，j:指向每一个word头部之前)
				q[words[i][0] - 'a'].emplace(i, 0);
			}
			int res = 0;
			//遍历s字符串
			// i:指向s,遍历一遍    j:指向各个word,从头到尾或到中间遍历
			for (auto c : s) {
				//取出对应子queue，&避免拷贝
				auto &subq = q[c - 'a'];
				int size = subq.size();
				while (size--) { //遍历当前开头的word
					auto [i, j] = subq.front();
					subq.pop();
					j++;//将每个指向word的指针向后移一位
					if (j == words[i].size()) {
						res++;
					} else {
						q[words[i][j] - 'a'].emplace(i, j);
					}
				}
			}
			return res;
		}
};
