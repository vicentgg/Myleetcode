#include<iostream>
#include<vector>

using namespace std;

class Soltuion {
public:
    int MaxNum(int& count, vector<int>& nums) {
        int len = nums.size();

        vector<int> record(len, 0);

        for(int i = 2; i < len; i ++) {
            if(nums[i] == nums[i-1] * nums[i-2] % 2021) {

                if(record[i - 1] != 0) {
                    record[i] = record[i - 1] + 1;
                } 
                else {
                    record[i] = 3;
                }

            }
        }

        int max = 0;
        for(int i = 0; i < len; i ++) {
            if(record[i] > max) max = record[i];
        }

        return max;

    }
};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    while(n) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int count = 0;
    int max = 0;

    Soltuion s;
    max = s.MaxNum(count, nums);

    cout << max << endl;

    return 0;
}