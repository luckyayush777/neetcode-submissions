class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& element : tokens){
            if(element == "/" || element == "+" || element == "-" ||
                     element == "*"){
                        int operand1;
                        int operand2;
                        operand2 = st.top();
                        st.pop();
                        operand1 = st.top();
                        st.pop();
                        switch(element[0]){
                            case '+': st.push(operand1 + operand2);
                                      break;
                            case '-': st.push(operand1 - operand2);
                                      break;
                            case '*': st.push(operand1 * operand2);
                                      break;
                            case '/': st.push(operand1 / operand2);
                                      break;
                        }

                        
                     }
            else{
                st.push(stoi(element));
            }  

        }
        return st.top();
    }
};
