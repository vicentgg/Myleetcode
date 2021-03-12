#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int trueNum = 0;
        if(guess[0] == answer[0])trueNum ++;
        if(guess[1] == answer[1])trueNum ++;
        if(guess[2] == answer[2])trueNum ++;

        return trueNum;

        return !(guess[0]^answer[0])+!(guess[1]^answer[1]) + !(guess[2]^answer[2]);
    }
};

int main(void) {

}