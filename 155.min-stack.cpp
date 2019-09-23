/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
using namespace std;
#include<stack>;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        // if x is smaller or equal to the top of minstck, push it into s2
        if(s2.empty()||x <= s2.top()) s2.push(x);
    }
    
    void pop() {
        if(s1.top() == s2.top()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    // use two stack to seperately record the stack of all numbers and minimum elements.
    stack<int> s1, s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

