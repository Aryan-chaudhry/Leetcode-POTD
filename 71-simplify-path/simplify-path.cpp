class Solution {
public:
    void buildAns(stack<string>&st, string &ans){
        if(st.empty()){
            return;
        }

        string temp = st.top();
        st.pop();

        buildAns(st,ans);

        ans += temp;
    }
    string simplifyPath(string path) {
        stack<string>st;

       int i=0;
       while(i < path.length()){
            int s = i;
            int end = i+1;

            while(end < path.length() && path[end] != '/'){
                end++;
            }
            string minPath = path.substr(s, end-s);
            i = end;

            if(minPath == "/" || minPath == "/.") continue;
            if(minPath != "/.."){
                st.push(minPath);
            }
            else if(!st.empty()){
                st.pop();
            }
       }

        string ans = st.empty() ? "/" : "";
        buildAns(st,ans);
        return ans;

    }
};