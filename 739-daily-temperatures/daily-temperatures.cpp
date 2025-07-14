class Solution {
public:
    void solve(vector<int>& temperatures, vector<int>&ans, stack<int>&st, int n){
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(st.top()-i);
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans;
        stack<int>st;

        solve(temperatures, ans, st, n);
        return ans;
    }
};