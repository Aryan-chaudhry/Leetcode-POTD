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
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            store.push_back(candidates[i]);
            solve(candidates, target-candidates[i], ans, store, i+1);
            store.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>store;
        int index = 0;
        solve(candidates, target, ans, store, index);
       
        return ans;
    }
};