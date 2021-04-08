#include<iostream>

using namespace std;

class Solution {
public:
    int sumNums(int n) {

        //当n到0时  便是递归出口
        n && (n += sumNums(n-1));
        return n;
        

    }
};

int main(void) {


    
}