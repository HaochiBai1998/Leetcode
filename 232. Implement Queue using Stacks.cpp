//
// Created by bhc on 2022/3/13.
//
#include<stack>
using namespace std;
class MyQueue {
    stack<int> stack1;
    stack<int> stack2;
public:
    void push(int x) {
        stack1.push(x);
    }

    int pop() {
        if(!stack2.size()){
            int n=stack1.size();
            for(int i=0;i<n;++i){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ans=stack2.top();
        stack2.pop();
        return ans;
    }

    int peek() {
        if(!stack2.size()){
            int n=stack1.size();
            for(int i=0;i<n;++i){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ans=stack2.top();
        return ans;
    }

    bool empty() {
        return stack1.empty()&&stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */