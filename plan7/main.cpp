#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Soltuion {
public:
    int ans(vector<int>& nums) {
        int ret;
        int len = nums.size();
        int n = len / 2;
        vector<int> counts(n + 1);
        //先对数组进行排序
        sort(nums.begin(), nums.end());

        //人数为2时 只有两艘单人船
        if(len == 2) return nums[1] - nums[0];

        //排除掉最大的两个人  然后前面的人首尾相加 
        for(int i = 0; i <= n - 2; i ++) {
            counts[i] = nums[i] + nums[len - 3 - i];
        }
        counts[n - 1] = nums[len - 2];
        counts[n] = nums[len - 1];

        sort(counts.begin(), counts.end());
         
        ret = counts[n] - counts[0];

        return ret;
    }
};

int main(void) {
    int n;
    cin >> n;

    vector<int> nums;
    for(int i = 0; i < 2*n; i ++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Soltuion s;

    cout << s.ans(nums);

    return 0;

}