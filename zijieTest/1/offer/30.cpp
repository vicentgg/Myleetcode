#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//调用 min、push 及 pop 的时间复杂度都是 O(1)。
class MinStack {
private:
    stack<int> s1;  //原始栈 存放原始信息
    stack<int> s2;  //维持递减顺序的栈
public: 
    MinStack() {
        
    }

    void push(int x) {
        s1.push(x);
        if(s2.empty() || s2.top() >= x) s2.push(x);
    }

    void pop() {
        if(!s1.empty()) {
            if(s1.top() == s2.top()) {
                s1.pop();
                s2.pop();
            }else s1.pop();
        }
    }

    int top() {
        return s1.top();
    }

    int min() {
        return s2.top();
    }
};

int main(void) {

}