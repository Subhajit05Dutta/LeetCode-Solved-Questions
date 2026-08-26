class MinStack {
public:
    stack<int> st;
    stack<int> st1;
    stack<int> st2;
    MinStack() {}

    void push(int value) {
        st.push(value);
        while (!st1.empty() && st1.top() < value) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(value);
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    void pop() {
        if (!st.empty()) {
            int ele = st.top();
            st.pop();
            while (!st1.empty() && ele != st1.top()) {
                st2.push(st1.top());
                st1.pop();
            }
            st1.pop();
            while (!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        }
    }

    int top() { return st.top(); }

    int getMin() { 
        return st1.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */