#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(base));
    }
};
 
int main(void) {

}