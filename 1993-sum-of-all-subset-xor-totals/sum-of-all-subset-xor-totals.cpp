class Solution {
public:
    int storeXor(vector<int>store){
        int xr = 0;

        for(int i=0; i<store.size(); i++){
            xr ^= store[i];
        }

        return xr;
    }

    void solve(vector<int>&nums, int index, vector<int>store, int &sum){
        // base case
        if(index >= nums.size()){
            sum += storeXor(store);
            return;
        }

        // how to tackle this

        // include / exclude

        // for including insert element 
        store.push_back(nums[index]);
        solve(nums, index+1, store, sum);
        // for excluding
        store.pop_back();
        solve(nums, index+1, store, sum);
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        vector<int>store;

        int index = 0; // for traversing on nums array

        solve(nums, index, store, sum);
        return sum;
    }
};