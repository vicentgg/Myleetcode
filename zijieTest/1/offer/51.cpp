#include<algorithm>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

//51
//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组，求出这个数组中的逆序对的总数。

//回顾一下  回溯法
//但是这道题 超出时间范围 这种解法不行
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public: 
    void backtrack(vector<int>& nums, int len, int start) {
        if(path.size() == 2) {
            res.push_back(path);
            return;
        }

        for(int i = start; i < len; i ++) {
            if(path.empty() || !path.empty()&&nums[i] < path[path.size()-1]) {
                path.push_back(nums[i]);
                backtrack(nums, len, i+1);
                path.pop_back();
            }
            
        }
    }

    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return 0;

        backtrack(nums, len, 0);

        return res.size();
    }

    //归并排序
    //归并排序的每个步骤 都与逆序对相关 在排序的同时 可以统计数组中有多少个逆序对
    int reversePairs(vector<int>& nums) { 
        vector<int> temp(nums.size());
        return mergeSort(0, nums.size()-1, nums, temp);
    }

    //两段有序数组 进行合并
    int mergeSort(int left, int right, vector<int>& nums, vector<int>& temp){
        if(left >= right) return 0;
        int mid = left + (right - left) / 2;
        int res = mergeSort(left, mid, nums, temp) + mergeSort(mid + 1, right, nums, temp);
        int i,j,k;
        for(k = left;k <= right; k ++) temp[k] = nums[k];

        for(i = left, j = mid + 1, k = left; i <= mid && j <= right;) {
            if(temp[i] <= temp[j]) nums[k++] = temp[i++];
            else {  //当前面数组的数大于后面数组的数时 则前面数组剩余的所有数都比这个数要大 所以都是一个逆序对
                nums[k++] = temp [j++];
                res += mid - i + 1;
            }
        }
        while(i <= mid) nums[k++] = temp[i++];
        while(j <= right) nums[k++] = temp[j++];

        return res;
    }

};


int main(void) {

}