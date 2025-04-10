class Solution {
public:
    void solve(vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>&store, int index ){
        if(target == 0){
            ans.push_back(store);
            return;
        }

        if(target < 0){
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            store.push_back(candidates[i]);
            solve(candidates, target-candidates[i], ans, store, i);
            store.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>store;
        int index = 0;
        solve(candidates, target, ans, store, index);
        return ans;
    }
};