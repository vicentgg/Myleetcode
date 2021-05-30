#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


class Solution {
public:
    //14-1
    int cuttingRope(int n) {
        int max = 0;
        if(n < 4) return n - 1;
        for(int i = 2; i <= n / 2; i ++) {
            int factorial = n / i;
            int remainder = n % i;
            int ans = pow(i, factorial - 1);
            ans *= (i + remainder);
            max = max > ans ? max : ans;
        }
        return max;
    }
};

int main(void) {
    
}