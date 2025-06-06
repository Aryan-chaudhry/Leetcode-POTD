class Solution {
public:
    bool isPossible(vector<int>&bloomDay, int day, int m , int k){
        int trackK = 0;
        int no_of_bucket = 0;

        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                trackK++;
            }
            else{
               no_of_bucket += (trackK/k);
               trackK = 0;
            }
        }
        no_of_bucket += (trackK/k);
        return no_of_bucket >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int st = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(isPossible(bloomDay, mid, m, k)){
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