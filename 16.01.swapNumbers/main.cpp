#include<iostream>
#include<vector>

using namespace std;

/*
编写一个函数，不用临时变量，直接交换numbers = [a, b]中a与b的值。
*/

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {

        //异或解法 强啊
        
        numbers[1] ^= numbers[0];
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0]; 
        
        return numbers;
    }
};

int main(void) {

}