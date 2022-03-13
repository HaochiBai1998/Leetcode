//
// Created by bhc on 2022/3/13.
//

class MyStack {
    queue<int> que1;
public:
    MyStack() {

    }

    void push(int x) {
        int n=que1.size();
        que1.push(x);
        for(int i=0;i<n;++i){
            que1.push(que1.front());
            que1.pop();
        }
    }

    int pop() {
        int ans= que1.front();
        que1.pop();
        return ans;
    }

    int top() {
        return que1.front();
    }

    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */