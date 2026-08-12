class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        st.push(n-1);
        for(int i = n - 2; i >= 0; i--){
            if(temperatures[st.top()] <= temperatures[i]){
                while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i] = 0;
                    st.push(i);
                }else{
                    ans[i] = st.top() - i;
                    st.push(i);
                }
            }else if(temperatures[i] < temperatures[st.top()]){
                ans[i] = st.top() - i;
                st.push(i);
            }
        }
        return ans;
    }
};
