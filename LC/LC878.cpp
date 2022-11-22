#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    //L-1始终是红色，R+1始终是蓝色
    const int MOD = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long l=min(a,b);//下界
        long r=(long)n*min(a,b);//上界
        int c = lcm(a,b);//a,b的最小公倍数
        while (l<=r) {
            long mid = l+(r-l)/2;
            long cnt = mid/a+mid/b-mid/c;//神奇数字的个数
            //找到满足条件的
            if(cnt>=n){
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        //终止条件：l一定在r的左边一个位置
        return (r+1)%MOD;
    }
    //关于lcm的计算：
    /*    
    lcm=(a*b)/(gcd(a,b));
    //最大公约数
    int gcd (int a,int b){
        while(a!=0){
            int temp=b%a;
            b=a;
            a=temp;
        }
        return b;
    }
    */
};