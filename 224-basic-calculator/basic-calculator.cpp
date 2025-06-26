class Solution {
public:
    int calculate(string s) {
        stack<int>st;

        int result = 0;
        int num = 0;
        int sign = 1;

        for(auto ch : s){
            if(isdigit(ch)){
                num = num*10 + (ch-'0');
            }
            else if(ch == '+'){
                result += sign*num;
                sign = 1;
                num = 0;
            }
            else if(ch == '-'){
                result += sign*num;
                sign = -1;
                num = 0;
            }
            else if(ch == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if(ch == ')'){
                result += sign * num;
                int sign = st.top();
                st.pop();
                result *= sign;
                result += st.top();
                st.pop();
                num = 0;
            }
        }
        result += sign*num;
        return result;

    }
};