class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int>mp;
        vector<int>ans;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                mp[grid[i][j]]++;
            }
        }

        for(auto &[num, freq] : mp)
            if(freq == 2)
                ans.push_back(num);

        
        set<int>s;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                s.insert({grid[i][j]});
            }
        }

        int n = grid.size()*grid.size();
        int totalSum = n*(n+1)/2;
        int sum = 0;

        for(auto num : s){
            sum += num;
        }

        int b = totalSum-sum;
        ans.push_back(b);

        return ans;
    }
};