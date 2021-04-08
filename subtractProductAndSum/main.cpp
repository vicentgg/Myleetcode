#include<iostream>
#include<vector>

using namespace std;

/*

给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。

*/

class Solution {
public:
    int subtractProductAndSum(int n) {

        int sum = 0;
        int product = 1;

        while(n) {

            sum += n % 10;
            product *= n % 10;

            n = n / 10;
        }

        return product - sum;

    }

};

/*
请你设计一个可以解释字符串 command 的 Goal 解析器 。
command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成。
Goal 解析器会将 "G" 解释为字符串 "G"、"()" 解释为字符串 "o" ，"(al)" 解释为字符串 "al" 。
然后，按原顺序将经解释得到的字符串连接成一个字符串。
*/

class Solution1 {
public:
    string interpret(string command) {
        string a;
        int i = 0;


        while( i < command.length()) {
            if(command[i] == 'G') {
                a += 'G';
                i++;
            }
            else if(command[i+1] == ')') {
                a += 'o';
                i += 2;
            }
            else {
                a += "al";
                i += 4;
            }
        }

        return a;
    }
};

/*

给你两个整数数组 nums 和 index。你需要按照以下规则创建目标数组：

目标数组 target 最初为空。
按从左到右的顺序依次读取 nums[i] 和 index[i]，在 target 数组中的下标 index[i] 处插入值 nums[i] 。
重复上一步，直到在 nums 和 index 中都没有要读取的元素。
请你返回目标数组。

题目保证数字插入位置总是存在


*/

class Solution2 {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {

        vector<int> target;

        for(int i = 0; i < index.size(); i ++) {
            target.insert(target.begin()+index[i], nums[i]);
        }

        return target;
        
    }
};

int main(void) {

}