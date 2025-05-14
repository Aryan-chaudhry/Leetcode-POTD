class Solution {
public:
    bool totalHour(vector<int>&piles, int k, int hr){
        long long int totalHr = 0;
        for(int i=0; i<piles.size(); i++){
            totalHr += ceil(piles[i]/(double)k);
        }

        return totalHr <= hr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int end = *(max_element(piles.begin(), piles.end()));
        int ans = 0;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(totalHour(piles, mid, h)){
                ans = mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
            mid = st + (end - st)/2;
        }
        return ans;
    }
};