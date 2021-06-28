#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

class MaxQueue {
private: 
    queue<int> q; //普通队列
    deque<int> maxq;  //双端队列

public: 
    MaxQueue() {
        while(!q.empty()) q.pop();
        while(!maxq.empty()) maxq.pop_back(); 
    }

    int max_value() {
        if(q.empty()) return -1;
        return maxq.front();
    }

    void push_back(int value) {
        q.push(value);
        while(!maxq.empty() && maxq.back() < value) {
            maxq.pop_back();
        }
        maxq.push_back(value);
    } 

    int pop_front() {
        if(q.empty()) return -1;
        int val = q.front();
        if(val == maxq.front()) {
            maxq.pop_front();
        }
        q.pop();

        return val;
    }
};

int main(void) {

}