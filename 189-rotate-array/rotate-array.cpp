class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k%size;

        int track = size-k;
        vector<int>store;

        // store last k elements
        for(int i=track; i<size; i++){
            store.push_back(nums[i]);
        }

        // shift array by k place
        for(int i=size-1; i>=0; i--){
            if(i-k >= 0){
                nums[i] = nums[i-k];
            }
        }

        // insert element in the begning which we store
        for(int i=0; i<store.size(); i++){
            nums[i] = store[i];
        }
    }
};