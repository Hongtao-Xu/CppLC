# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;

int main(){
    vector<int> mask(4,0);
    vector<int> ip1(4,0);
    vector<int> ip2(4,0);
    char c;
    while(cin>>mask[0]>>c>>mask[1]>>c>>mask[2]>>c>>mask[3]){//输入掩码
        int flag =-1;
        cin>>ip1[0]>>c>>ip1[1]>>c>>ip1[2]>>c>>ip1[3];
        cin>>ip2[0]>>c>>ip2[1]>>c>>ip2[2]>>c>>ip2[3];
        //开始处理
        //1.判断格式
        int i=0,j=0;
        while(i<4){
            if(mask[i]<0||mask[i]>255||ip1[i]<0||ip1[i]>255||ip2[i]<0||ip2[i]>255){
                flag=1;
                break;
            }
            i++;
        }
        while(j< 3){
            if(mask[j]<255&&mask[j+1]>0){
                flag=1;
                break;
            }
            j++;
        }
        //2.AND运算
        if(flag==1){
            cout<<flag<<endl;
        }else{
            for(int i=0;i<4;i++){
                if((mask[i]&ip1[i])!=(mask[i]&ip2[i])){
                    flag=2;
                    break;
                }else{
                    flag=0;
                }
            }
            cout<<flag<<endl;
        }
    }
    return 0;
}