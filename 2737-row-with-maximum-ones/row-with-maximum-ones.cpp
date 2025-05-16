class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        map<int,int>mp;

        for(int i=0; i<mat.size(); i++){
            int count = 0;
            int row = i;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            mp[row] = count;
        }

        // find max count of 1 
        int maxCount = INT_MIN;

        for(auto i : mp){
            maxCount = max(maxCount, i.second);
        }

        // find the row having maxCount
        int row = 0;

        for(auto i : mp){
            if(i.second == maxCount){
                row = i.first;
                break;
            }
        }

        return {row, maxCount};
    }
};