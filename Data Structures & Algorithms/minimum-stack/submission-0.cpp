class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int, int> pair_element;
            pair_element.first = val;
            pair_element.second = val;
            st.push(pair_element);
        }else {
            pair<int, int> pair_element;
            pair_element.first = val;
            int min = INT_MAX;
            if(val <= st.top().second){
                min = val;
            }else{
                min = st.top().second;
            }
            pair_element.second = min;
            st.push(pair_element);
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
