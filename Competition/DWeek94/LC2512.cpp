#include <bits/stdc++.h>
#include <sstream>


using namespace std;

//利用stringStream实现空格分隔
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        //单词映射到分数
        unordered_set<string>good,bad;//set存储
        for(auto &g:positive_feedback)good.insert(g);
        for(auto &b:negative_feedback)bad.insert(b);
        unordered_map<int, int> mark(student_id.size());//存储【studentID,mark】
        // 把每个学生的信息统计出来
        for(int i=0;i<report.size();++i){
            stringstream ss;//实现空格分隔
            string a;
            ss<<report[i];
            while(ss>>a){
                if(good.find(a)!=good.end())
                    mark[student_id[i]]+=3;
                else if(bad.find(a)!=bad.end())
                    mark[student_id[i]]--;
            }
        }
        //排序，自定义规则
        sort(student_id.begin(),student_id.end(),[&](int a,int b){
            if(mark[a]<mark[b])
                return false;
            else if (mark[a]>mark[b])
                return true;
            else
                return a<b;
        });
        //返回前k个
        return vector<int>(student_id.begin(),student_id.begin()+k);
    }
};