#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;


//计算x的n次方 注意不要越界 
class Solution {
public: 
    double myPow(double x, int n) {
        double res = 1;
        if(x == 0) return 0;
        if(x == 1 || n == 0) return 1;

        int t = abs(n);

        long i;
        res = x;

        for(i = 2;i <= t; i *= 2) {
            res *= res;
        }

        if(i / 2 < t) res *= myPow(x, t - i / 2);

        if(n < 0) res = 1 / res;

        return res;
    }
};

int main(void) {

}

