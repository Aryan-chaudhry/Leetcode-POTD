class Solution {
public: 
    int solve(vector<int>&weights, int capacity){
        int days = 1;
        int load = 0;
        
        for(int i=0; i<weights.size(); i++){
            if(load + weights[i] > capacity){
                days = days + 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int st = *(max_element(weights.begin(), weights.end()));
        int end = accumulate(weights.begin(), weights.end(), 0);
        int minCapacity = -1;

        while(st <= end){
            int mid = st + (end - st)/2;
            
            if(solve(weights, mid) <= days){
                minCapacity = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
            mid = st + (end - st)/2;
        }
        return minCapacity;
    }
};