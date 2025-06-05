class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0;
        int end = nums.size()-1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(st == end) return nums[st];

            int curr = nums[mid];
            int leftvalue = -1;

            if(mid-1 >= 0){
                leftvalue = nums[mid-1];
            }

            int rightvalue = -1;
            if(mid+1 < nums.size()){
                rightvalue = nums[mid+1];
            }

            if(curr != leftvalue && curr != rightvalue){
                return curr;
            }

            else if(curr == leftvalue && curr != rightvalue){
                int pairIndex = mid-1;
                if(pairIndex&1){
                    //odd
                    end = mid -1;
                }
                else{
                    st = mid + 1;
                }
            }
            else{
                int pairIndex = mid;
                if(pairIndex&1){
                    // odd
                    end = mid -1;
                }
                else{
                    st = mid + 1;
                }
            }
        }
        return -1;
    }
};