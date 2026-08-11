class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char top;
        for(auto& element : s){
            if(!st.empty())
                top = st.top();
            if(element == '[' || element == '{' || element == '('){
                st.push(element);
            }else if((element == ']' && top == '[') || 
                     (element == '}' && top == '{') ||
                     (element == ')' && top == '(')){
                        if(!st.empty()){
                            st.pop();
                        }else {
                            return false;
                        }
                    }
            else {
                return false;
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};
