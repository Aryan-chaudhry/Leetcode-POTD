class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{
            int temp = st.top().second;
            if(temp < val){
                st.push({val, temp});
            }
            else{
                st.push({val,val});
            }
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int ans = st.top().first;
        return ans;
    
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */