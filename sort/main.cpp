#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //直接插入排序  稳定排序
    void InsertSort(vector<int>& nums) {

        int temp;
        int len = nums.size();

        for(int i = 1; i < len; i++) {
            if(nums[i] < nums[i - 1]) {
                temp = nums[i];

                int j;
                for(j = i - 1; temp < nums[j] && j >= 0; j --) {
                    nums[j+1] = nums[j];
                }

                nums[j+1] = temp;
            }
        }
    }

    //折半插入排序  稳定排序
    void InsertSortB(vector<int>& nums) {
        int temp = 0;
        int len = nums.size();

        for(int i = 1; i < len; i++) {

            if(nums[i] < nums[i-1]) {
                temp = nums[i];

                int low = 0;
                int high = i - 1;
                while (low <= high)
                {
                    int mid = (low + high) / 2;
                    if(temp < nums[mid]) high = mid - 1;
                    else low = mid + 1;
                }

                for(int j = i - 1; j >= high + 1; j --) {
                    nums[j+1] = nums[j];
                }
            
                nums[high+1] = temp;
            }
            
        }
    }


    //希尔排序  不稳定的排序  通过增大直接插入排序的步长 减少时间
    void hillInsertSort(vector<int>& nums) {
        int temp;
        int len = nums.size();

        for(int dk = len/2; dk >= 1; dk = dk/2) {
            for(int i = dk; i < len; i ++) {

                if(nums[i] < nums[i - dk]) {
                    temp = nums[i];

                    int j;
                    for(j = i - dk; temp < nums[j] && j >= 0; j -= dk) {
                        nums[j+dk] = nums[j];
                    }
                    nums[j+dk] = temp;
                }
                
            }
        }
    }

    //冒泡排序 稳定排序 交换排序
    void BubbleSort(vector<int>& nums) {
        bool flag;
        int len = nums.size();

        for(int i = 0; i < len; i ++) {
            flag = false;

            for(int j = len-1; j > i; j--) {
                if(nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j-1]);
                    flag = true;
                }
            }

            if(flag == false)return;
        }
    }

    //快速排序  不稳定排序   当数组有序或逆序的时候 时间复杂度最高
    void QuickSort(vector<int>& nums, int low, int high) {
        if(low < high) {
            int pivotpos = Partiton(nums, low, high);
            QuickSort(nums, low, pivotpos - 1);
            QuickSort(nums, pivotpos + 1, high);
        }
    }

    int Partiton(vector<int>& nums, int low, int high) {
        int pivot = nums[low];

        while(low < high) {
            while(low < high && nums[high] >= pivot) --high;
            nums[low] = nums[high];

            while(low < high && nums[low] <= pivot) ++low;
            nums[high] = nums[low];
        }
        nums[low] = pivot;

        return low;
    }

    //简单选择排序  不稳定的排序
    void SelectSort(vector<int>& nums) {
        int min;
        int len = nums.size();

        for(int i = 0; i < len-1; i ++) {
            min = i;
            
            for(int j = i + 1; j < len; j ++) {
                if(nums[min] > nums[j]) min = j;
            }

            if(min != i)swap(nums[i], nums[min]);
        }
    }

    // 堆排序


};

int main(void) {
    int n;
    cin >> n;
    vector<int> nums;

    while(n--) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution solution;


    solution.InsertSortB(nums);

    for(auto it : nums) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}