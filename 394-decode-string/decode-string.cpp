class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        
        for(auto ch : s){
            if(ch == ']'){
                string stringToRepeat;
                while(!st.empty() && !isdigit(st.top()[0])){
                    string top = st.top();
                    stringToRepeat += top == "["  ? "" : top;
                    st.pop();
                }

                string number = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    number += st.top();
                    st.pop();
                }
                reverse(number.begin(), number.end());
                int n = stoi(number);

                string currDecode = "";
                while(n--){
                    currDecode += stringToRepeat;
                }
                st.push(currDecode);
            }
            else{
                string temp(1,ch);
                st.push(temp);
            }
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};