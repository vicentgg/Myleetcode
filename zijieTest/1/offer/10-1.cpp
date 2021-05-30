#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //这个方法会涉及到大量的重复运算
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        return fib(n - 1) + fib (n - 2);
    }

    //动态规划
    //用三个值 依次向下计算 最后返回一个值a 即可 不用单独判断=0的情况
    int fib(int n) {
        int a = 0, b = 1;
        int sum;

        for(int i = 0; i < n; i ++) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        
        return a;
    }

    // 10-2 青蛙跳台阶
    int numWays(int n) {

        int a = 1; //f(0) = 1
        int b = 1; //f(1) = 1
        int sum; //f(2) = 2  f(n) = f(n-1) + f(n -2)

        for(int i = 0; i < n; i ++) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }

        return a;
    }
};

int main(void) {
    
}