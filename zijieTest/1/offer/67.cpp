#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int len = str.size();
        if(len == 0) return 0;
        int i = 0, res = 0, signal = 1; 
        int temp = INT_MAX / 10;

        while(str[i] == ' ') i ++;
        if(str[i] == '-') signal = -1;
        if(str[i] == '-' || str[i] == '+') i ++;

        for(int j = i; j < len; j ++) {
            if(str[j] < '0' || str[j] > '9') break;
            if(res > temp || res == temp && (str[j] - '0' > 7)) {
                return signal == 1 ? INT_MAX : INT_MIN;
            }
            res = res*10 + (str[j] - '0');
        }

        return res*signal;
    }
};

int main(void) {

}