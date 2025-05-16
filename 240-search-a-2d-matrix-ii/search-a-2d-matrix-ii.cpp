class Solution {
public:
    bool search(vector<int>&arr, int target){
        int st = 0, end = arr.size()-1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(arr[mid] == target){
                return true;
            }
            else if(target < arr[mid]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(int i=0; i<matrix.size(); i++){
            bool ans = search(matrix[i], target);
            if(ans == true){
                return true;
            }
        }
        return false;
    }
};