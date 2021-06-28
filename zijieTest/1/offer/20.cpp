#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public: 
    bool isNumber(string s) {
        string ans="";
        int first=0;
        int last=s.size()-1;
        while(first<s.size()&&s[first]==' ')first++;
        while(last>=0&&s[last]==' ')last--;
        ans=s.substr(first,last+1-first);
        //以上去除首位空格
        for(int i=0;i<ans.size();i++){
            if(ans[i]==' ')return false;
        }//中间如果仍有空格，false
        if(ans.size()==0)return false;//如果为空返回false
        int i=0;
        bool flag=false;
        for(;i<ans.size();i++){
            if(ans[i]=='e'||ans[i]=='E'){
                flag=true;//记录是否存在e以及E的位置
                break;
            }
        }

        string pre=ans.substr(0,i);
        string aft=i<ans.size()?ans.substr(i+1):"";
        //以上将去除首尾空格的字符串以e为界限分隔开

        if(flag&&aft.size()==0)return false;
        int ans1=0;
        bool c1=check(pre,ans1);
        int ans2=0;
        bool c2=check(aft,ans2);

        if(ans1>=2||ans2>0)return false;//ans判断小数点的个数
        return c1&&c2&&pre.size()!=0;
    }

    bool check(string &s,int &ans){//判断是否是数字的函数
        if(s.size()==0)return true;
        if(s.size()==1&&(s[0]<'0'||s[0]>'9'))return false;
        for(int i=0;i<s.size();i++){
            if(i==0&&(s[0]=='+'||s[0]=='-')){
                if(s.size()==2&&s[1]=='.')return false;
                continue;
            }
            if(s[i]=='.'){ans++;}
            else if(s[i]<'0'||s[i]>'9')return false;
        }
        return true;
    }
};


int main(void) {

}