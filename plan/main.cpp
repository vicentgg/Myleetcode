#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> ans(vector<vector<int>>& nums, int r1, int r2, int c1, int c2, int s, int a) {

        //对s列 进行冒泡排序 记录变动下标
        for(int i = r1 - 1; i < r2 - 1; i ++ ) {

            int temp = nums[i][s-1];
            int signl = r1 - 1;
           
            for(int j = i + 1; j < r2 ; j ++ ){
                if(a == 0) {
                    if(nums[j][s-1] < temp) {
                    
                        temp = nums[j][s-1];
                        for(int k = c1 - 1; k < c2; k ++) {
                            
                            swap(nums[i][k],nums[j][k]);

                        }
                        
                    }
                }
                else if(a == 1) {
                    if(nums[j][s-1] > temp) {
                     
                        temp = nums[j][s-1];
                        for(int k = c1 - 1; k < c2; k ++) {
                            
                            swap(nums[i][k],nums[j][k]);

                        }
                    }
                }  
            }

        }

        
        return nums;
        
    }
};

int main(void) {
    int n, m, time;
    cin >> n;
    cin >> m;
    cin >> time;

    vector<vector<int>> nums(n);
    for(int i = 0; i < n; i ++) {
        nums[i].resize(m);
    }

    for(int i = 0 ; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> nums[i][j];
        }
    }
    
    Solution solution;
    vector<vector<int>> ans;

    while(time > 0) {
        int row1,row2,col1,col2,s,a;
        cin >> row1;
        cin >> row2;
        cin >> col1;
        cin >> col2;
        cin >> s;
        cin >> a;
    
        ans = solution.ans(nums, row1, row2, col1, col2, s, a);

        time --;
    
    }

      for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    
}