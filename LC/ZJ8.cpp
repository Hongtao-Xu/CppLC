#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


int main() {
    int n, q;

    cin >> n; //输入人数
    vector<int> user(n);//数组：保存用户喜爱编号
    for (int i = 0; i < n; i++)
        cin >> user[i]; //输入用户偏好

    cin >> q; //查询组数
    vector<int> l(q), r(q), k(q);//查询区间起点l，终点r，喜好度k
    for (int i = 0; i < q; i++)
        cin >> l[i] >> r[i] >> k[i];

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
        mp[user[i]].push_back(i + 1);//每个喜好度对应用户的标号存入vector与喜好度对应（注意下标+1）

    vector<int> res(q, 0);//默认结果都是0
    //查找
    for (int i = 0; i < q; i++) {
        if (mp.count(k[i]) != 0) //如果该喜好度用户数不为0
        {
            vector<int> p = mp[k[i]];//喜好度对应的用户下标
            res[i] = upper_bound(p.begin(), p.end(), r[i]) - lower_bound(p.begin(), p.end(), l[i]);
            //p.end()-1=1
        }
    }
    for (int i = 0; i < q; i++)
        cout << res[i] << endl;
    return 0;
}












