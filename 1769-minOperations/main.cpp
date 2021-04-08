#include<iostream>
#include<vector>

using namespace std;

/*
有 n 个盒子。给你一个长度为 n 的二进制字符串 boxes ，其中 boxes[i] 的值为 '0' 表示第 i 个盒子是 空 的，而 boxes[i] 的值为 '1' 表示盒子里有 一个 小球。

在一步操作中，你可以将 一个 小球从某个盒子移动到一个与之相邻的盒子中。第 i 个盒子和第 j 个盒子相邻需满足 abs(i - j) == 1 。注意，操作执行后，某些盒子中可能会存在不止一个小球。

返回一个长度为 n 的数组 answer ，其中 answer[i] 是将所有小球移动到第 i 个盒子所需的 最小 操作数。

每个 answer[i] 都需要根据盒子的 初始状态 进行计算。

*/


class Solution {
public:
    vector<int> minOperations(string boxes) {

        //动态规划求解
        /*

        假设某个位置的盒子操作数为total 右边有r个盒子有球 左边有l个盒子（包括自己）有球
        则盒子右边的盒子的操作数为total+l-r
        如果这个盒子有球的话 那么l++ r--
        没有则保持

        */

        int len = boxes.length();
        vector<int> count(len);

        int left = 0, right = 0, total = 0; //左边球数 右边球数  操作数

        //计算第一个盒子的操作数
        if(boxes[0] == '1') left ++;
        for(int i = 1; i < len; i ++) {
            if(boxes[i] == '1') {
                right ++;
                total += i;
            }
        }
        count[0] = total;

        //统计各个位置的操作数
        for(int i = 1; i < len; i ++) {
            total = total + left - right;
            if(boxes[i] == '1') {
                left ++;
                right --;
            }
            count[i] = total;
        }

        return count;
        
    }
};

int main(void) {


}