#include <bits/stdc++.h>
using namespace std;  
    
bool isnum(string s)  
{  
        stringstream sin(s);  
        double t;  
        char p;  
        if(!(sin >> t))  
        /*解释： 
            sin>>t表示把sin转换成double的变量（其实对于int和float型的都会接收），如果转换成功，则值为非0，如果转换不成功就返回为0 
        */  
               return false;  
        if(sin >> p)  
        /*解释：此部分用于检测错误输入中，数字加字符串的输入形式（例如：34.f），在上面的的部分（sin>>t）已经接收并转换了输入的数字部分，在stringstream中相应也会把那一部分给清除，如果此时传入字符串是数字加字符串的输入形式，则此部分可以识别并接收字符部分，例如上面所说的，接收的是.f这部分，所以条件成立，返回false;如果剩下的部分不是字符，那么则sin>>p就为0,则进行到下一步else里面 
          */  
                return false;  
        else  
                return true;  
}  
int main()  
{  
        string s;  
        while(cin >> s)  
        {  
                if(isnum(s))  
                        cout << s << " is a number." << endl;  
                else  
                        cout << s << " is not a number." << endl;  
        }  
} 