#include <iostream>
#include <stack> //引入栈文件
using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;
    
    void in2out(){
        while (!inStack.empty())
        {
            outStack.push(inStack.top());
            inStack.pop();
        }
        
    }

public:
    MyQueue(){

    }

    void push(int x){
        inStack.push(x);
    }

    int pop(){
        if(outStack.empty()){
            in2out();
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    //返回队列开头的元素
    int peek(){
        if(outStack.empty()){
            in2out();
        }
        return outStack.top();
    }

    bool empty(){
        return inStack.empty() && outStack.empty();
    }

};

int main(){

    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek() << endl; // return 1
    cout << myQueue.pop() << endl; // return 1, queue is [2]
    cout << myQueue.empty() << endl; // return false

}