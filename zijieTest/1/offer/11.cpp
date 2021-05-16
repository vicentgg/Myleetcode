#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//二分查找
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while(left < right) {
            int pivot = left + (right - left) / 2;

            //第一种情况 如果pivot 小于 right  代表pivot在最小值右侧
            if(numbers[pivot] < numbers[right]) right = pivot;
            //如果pivot 大于 right  代表pivot在最小值左侧
            else if(numbers[pivot] > numbers[right]) left = pivot + 1;
            //两者相同时 无法确定 所以减少right值
            else right --;
        }

        return numbers[left];
    }
};

int main(void) {

}