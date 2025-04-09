class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&store, int n, int k, int start){

        // base case
        if(k==0){
            ans.push_back(store);
            return;
        }

        for(int i=start; i<=n; i++){
            store.push_back(i);
            solve(ans, store, n, k-1, i+1);
            store.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>store;
        int start = 1;
        solve(ans, store, n, k, start);
        return ans;
    }
};