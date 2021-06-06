#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;//建立一个小顶堆 存放数组中较大的一半变量
    priority_queue<int,vector<int>,less<int>> maxHeap; //建立一个大顶堆 存放数组中较小的一半变量

public:
    MedianFinder() {
        while(!minHeap.empty()) minHeap.pop();
        while(!maxHeap.empty()) maxHeap.pop();
    }
    //规定数组长度为奇数时 大顶堆个数比小顶堆个数多1
    void addNum(int num) {

        //原数组长度为奇数时
        if(maxHeap.size() > minHeap.size()) {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        //原数组长度为偶数时
        else if(maxHeap.size() == minHeap.size()) {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if(minHeap.empty() && maxHeap.empty()) return NULL;
        double ans;
        if(maxHeap.size() > minHeap.size()) ans = maxHeap.top() * 1.0;
        else ans = (minHeap.top() + maxHeap.top()) * 1.0 / 2;
        return ans;
    }
};