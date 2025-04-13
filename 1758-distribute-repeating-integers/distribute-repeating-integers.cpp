class Solution {
public:

    bool solve(vector<int>&counts, vector<int>&quantity, int index){
        // base case
        if(index >= quantity.size()){
            return true;
        }
        // solve 1 case
        for(int i=0; i<counts.size(); i++){
            if(counts[i] >= quantity[index]){
                counts[i] -= quantity[index];
                if(solve(counts, quantity, index+1)){
                    return true;
                }
                // backtrack
                counts[i] += quantity[index];
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    sort(quantity.rbegin(), quantity.rend());
    
      unordered_map<int,int>countMap;

      for(auto no : nums){
          countMap[no]++;
      }

      vector<int>counts;

      for(auto it : countMap){
        counts.push_back(it.second);
      }

      return solve(counts, quantity, 0);


    }
};