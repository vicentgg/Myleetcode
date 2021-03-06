#include<iostream>
#include<vector>
#include<stack>

//题目
//给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），
//输出每个元素的下一个更大元素。
//数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，
//这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。


using namespace std;

class Solution{
public:

    //该方法超出时间限制 自己写的
    // //交换
    // void xunhun(vector<int>& nums) {
    //     int temp = nums[0];
    //     int len = nums.size();
    //     for(int i = 0; i < len - 1 ; i ++){
    //         nums[i] = nums[i+1];
    //     }
    //     nums[len-1] = temp;
    // }

    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     int length = nums.size();
    //     vector<int> count(length);
    
    //     int i = 0;
    //     while (i < length){ 

    //         int j;
    //         for(j = 1; j < length; j ++){
    //             if(nums[j] > nums[0]){
    //                 count[i] = nums[j]; //找到第一个最大数 原数组提前 跳出循环
    //                 break;
    //             }
    //         }
    //         if(j == length)count[i] = -1;

    //         xunhun(nums);

    //         i ++;
    //     }
    //     return count;
    // }

//每次我们移动到数组中的一个新的位置 i，
//我们就将当前单调栈中所有对应值小于 nums[i] 的下标弹出单调栈，
//这些值的下一个更大元素即为nums[i]（证明很简单：
//如果有更靠前的更大元素，那么这些位置将被提前弹出栈）。随后我们将位置 i 入栈。


    //正确做法
    //用栈记录数组下标
     vector<int> nextGreaterElements(vector<int>& nums) {
         int length = nums.size();
         stack<int> s;
         vector<int> count(length,-1);


         //注意必须循环两次  
         for(int i = 0; i < 2*length - 1; i ++){
             while(!s.empty() && nums[s.top()] < nums[i % length]){
                 count[s.top()] = nums[i % length];
                 s.pop();
             }
             s.push(i % length);
         }

         return count;
     }


};

int main(){

}