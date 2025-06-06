class Solution {
public:
    bool isPossible(vector<int>&weights, int capacity, int days){
        int load = 0;
        int no_of_day = 1;

        for(int i=0; i<weights.size(); i++){
            if(load + weights[i] > capacity){
                no_of_day++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return no_of_day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int st = *max_element(weights.begin(),weights.end());
        long long int end = accumulate(weights.begin(), weights.end(),0);
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(isPossible(weights, mid, days)){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }
};