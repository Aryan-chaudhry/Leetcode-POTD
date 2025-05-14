class Solution {
public:
    bool isPossible(vector<int>&bloomDay, int day, int m, int k){
        int count = 0;
        int no_of_b = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }
            else{
              no_of_b += (count/k);  
              count = 0;
            }
        }
        no_of_b += (count/k);
        return no_of_b >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int st = *(min_element(bloomDay.begin(), bloomDay.end()));
        int end = *(max_element(bloomDay.begin(), bloomDay.end()));

        while(st <= end){
            int mid = st + (end - st)/2;

            if(isPossible(bloomDay, mid, m, k)){
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