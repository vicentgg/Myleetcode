#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//使用两个栈 实现队列 添加的时候不需要操作 删除的时候 只需要判断s2是不是为空
class CQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    CQueue() {
        while (!s1.empty()) s1.pop();
        while (!s2.empty()) s2.pop();        
    }

    //入队列
    void appendTail(int value) {
       s1.push(value); 
    }

    int deleteHead() {
        if(s2.empty()) {
            if(s1.empty()) return -1;
            while (!s1.empty())
            {
                int t = s1.top();
                s1.pop();
                s2.push(t);
            }
        }
        int temp = s2.top();
        s2.pop();

        return temp;
    }

};

int main(void) {

}
