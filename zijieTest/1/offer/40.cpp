#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public: 

    //冒泡排序
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        for(int i = 0; i < k; i ++) {
            bool flag = false;
            for(int j = arr.size() - 1; j > i; j --) {
                if(arr[j] < arr[j - 1]) {
                    swap(arr[j], arr[j -1]);
                    flag = true;
                }
            }
            if(flag == false) break;
        }
        vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }


    //调整大顶堆
    void AdjustHeap(vector<int>& arr, int len, int x) {
        int temp = arr[x];
        for(int i = 2*x + 1; i < len; i = 2 * i + 1) {
            if(i < len - 1 && arr[i+1] > arr[i]) i ++;
            if(temp > arr[i]) break;
            else {
                arr[x] = arr[i];
                x = i;
            }
        }
        arr[x] = temp;
    }

    //建立一个大顶堆
    void BuildMaxHeap(vector<int>& arr, int len) {
        for(int i = (len / 2) - 1; i >= 0; i --) {
            AdjustHeap(arr, len, i);
        }
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        BuildMaxHeap(arr, k); //先将前k个数建立一个大顶堆
        for(int i = k; i < arr.size(); i ++) {
            if(arr[i] < arr[0]) {  //如果后面的数小于堆顶 则交换堆顶与该数的位置
                swap(arr[i], arr[0]);
                AdjustHeap(arr, k, 0); //从堆顶调整堆
            }
        }
        //对k个数进行排序
        for(int i = k - 1; i > 0; i --) {
            swap(arr[i], arr[0]);
            AdjustHeap(arr, i, 0);
        }
        vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }


};

int main(void) {

}