#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


class Solution {
public:
    //14-1 贪心算法
    int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        int a = n / 3;
        int b = n % 3;
        if(b == 0) return pow(3,a);
        else if(b == 1) return pow(3, a-1) * 4;
        return pow(3, a) * 2;
    }

    //14-2 
    int cuttingRope(int n) {
        long p = 1000000007;
        if(n <= 3) return n - 1;
        int a = n / 3;
        int b = n % 3;
        if(b == 0) return int(remainder2(3,a,p));
        else if(b == 1) return int((remainder2(3, a-1, p) * 4) % p);
        return int((remainder2(3, a, p) * 2) % p);
    }

    //循环幂求余
    long remainder(int x, int a, long p) {
        long rim = 1;
        for(int i = 0; i < a; i ++) {
            rim = (rim * x) % p;
        }
        return rim;
    }

    //快速幂求余
    long remainder2(int x, int a, long p) {
        long rim = 1;
        long tmp = x;
        while (a > 0)
        {
            if(a % 2 == 1) {
                rim = (rim * tmp) % p;
            }

            tmp *= tmp;
            tmp %= p;
            a /= 2;
        }
        return rim;
    }
};

int main(void) {
    
}