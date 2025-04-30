class Solution {
public:
   void merge(vector<int>& nums, int st, int mid, int end, int &count) {
    
    int j = mid + 1;
    for (int i = st; i <= mid; ++i) {
        while (j <= end && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // Now do the standard merge process
    int leftlength = mid - st + 1;
    int rightlength = end - mid;

    int *leftarr = new int[leftlength];
    int *rightarr = new int[rightlength];

    int index = st;

    for (int i = 0; i < leftlength; i++) {
        leftarr[i] = nums[index++];
    }

    for (int i = 0; i < rightlength; i++) {
        rightarr[i] = nums[index++];
    }

    int i = 0, k = 0, mainindex = st;

    while (i < leftlength && k < rightlength) {
        if (leftarr[i] <= rightarr[k]) {
            nums[mainindex++] = leftarr[i++];
        } else {
            nums[mainindex++] = rightarr[k++];
        }
    }

    while (i < leftlength) {
        nums[mainindex++] = leftarr[i++];
    }

    while (k < rightlength) {
        nums[mainindex++] = rightarr[k++];
    }

    delete[] leftarr;
    delete[] rightarr;
}


    void mergesort(vector<int>&nums, int st, int end, int &count){
        if(st >= end){
            return;
        }

        int mid = st + (end - st)/2; // --> (2st + end- st)/2 --> (st + end)/2

        mergesort(nums, st, mid, count);
        mergesort(nums, mid+1, end, count);
        merge(nums, st, mid, end, count);
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        int st = 0;
        int end = nums.size()-1;

        mergesort(nums, st, end, count);
        return count;
    }
};