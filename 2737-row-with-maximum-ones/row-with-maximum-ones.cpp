class Solution {
public:
    int lowerbound(vector<int>&mat, int target){
        int ans = mat.size();
        int st = 0, end = mat.size()-1;
        sort(mat.begin(), mat.end());

        while(st <= end){
            int mid = st + (end - st)/2;
            
            if(mat[mid] == target){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int maxCount = -1;
        int row = -1;
        int m = mat[0].size();

        for(int i=0; i<mat.size(); i++){
            int count = m - lowerbound(mat[i], 1);
            if(count > maxCount){
                maxCount = count;
                row = i;
            }
        }
        return {row, maxCount};
    }
};