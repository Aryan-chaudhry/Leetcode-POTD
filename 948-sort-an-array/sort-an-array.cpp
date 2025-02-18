class Solution {
public:
    void merge(vector<int>&nums, int st, int end, int mid){
        int leftLength = mid-st+1;
        int rightLength = end - mid;

        int *leftarr = new int[leftLength];
        int *rightarr = new int[rightLength];

        int index = st;

        for(int i=0; i<leftLength; i++){
            leftarr[i] = nums[index++];
        }

        for(int i=0; i<rightLength; i++){
            rightarr[i] = nums[index++];
        }

        int track = st;
        int i=0;
        int j=0;

        while(i<leftLength && j<rightLength){
            if(leftarr[i] <= rightarr[j]){
                nums[track++] = leftarr[i++];
            }
            else{
                nums[track++] = rightarr[j++];
            }
        }

        while(i < leftLength){
            nums[track++] = leftarr[i++];
        }

        while(j < rightLength){
            nums[track++] = rightarr[j++];
        }

        delete []leftarr;
        delete []rightarr;
    }
    void mergeSort(vector<int>&nums, int st, int end){
        // base case
        if(st >= end){
            return;
        }

        int mid = st + (end - st)/2;

        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, st, end, mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        int st = 0;
        int end = nums.size()-1;
        mergeSort(nums, st, end);
        return nums;
    }
};