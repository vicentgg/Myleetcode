#include<vector>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:

    //sort比较函数 为static型 且参数为常量引用
    static bool compare(const string& x, const string& y) {
        string xy = x + y;
        string yx = y + x;
        return xy < yx; //升序排序
    }

    string minNumber(vector<int>& nums) {

        //1.将数组中的数字 先转换为字符串
        vector<string> strs;
        for(int i = 0; i < nums.size(); i ++) {
            strs.push_back(to_string(nums[i]));
        }

        //对于两个字符串x,y
        //当x+y < y+x 则可认定x < y
        //2.根据已上规则 对字符串数组进行排序
        //使用内置快排函数
        sort(strs.begin(), strs.end(), compare);
        //使用自定义快排函数
        QuickSort(0, strs.size() - 1, strs);

        string ans;
        for(auto str : strs) {
            ans += str;
        }

        return ans;
    }

    //自定义快排函数
    void QuickSort(int low, int high, vector<string>& strs) {
        if(low >= high) return;
        int i = low;
        int j = high;
        while (i < j)
        {
            while(i < j && strs[j] + strs[low] >= strs[low] + strs[j]) j --;
            while(i < j && strs[i] + strs[low] <= strs[low] + strs[i]) i ++;
            swap(strs[i], strs[j]);
        }
        swap(strs[low], strs[i]);
        
        QuickSort(low, i - 1, strs);
        QuickSort(i + 1, high, strs);
    }
};

int main(void) {

}