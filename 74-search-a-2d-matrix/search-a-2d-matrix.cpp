class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();
        int totalElement = rowsize*colsize;

        int st = 0;
        int end = totalElement-1;

        while(st <= end){
            int mid = st + (end - st)/2;
            int rowindex = mid/colsize;
            int colindex = mid%colsize;

            if(target == matrix[rowindex][colindex]){
                return true;
            }
            else if(target < matrix[rowindex][colindex]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return false;
    }
};