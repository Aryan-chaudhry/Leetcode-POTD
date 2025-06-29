class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // creating min heap
        priority_queue<int, vector<int>, greater<int>>pq;

        // insert first k element
        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }

        for(int i=k; i<nums.size(); i++){
            int element = nums[i];

            if(element > pq.top()){
                pq.pop();
                pq.push(element);
            }
        }

        int ans = pq.top();
        return ans;


    }
};