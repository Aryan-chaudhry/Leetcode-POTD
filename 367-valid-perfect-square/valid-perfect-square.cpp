class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int st = 0;
        long long int end = num;

        long long int mid = st + (end - st)/2;
        bool ans = false;

        while(st <= end){
            if(mid*mid == num){
                ans = true;
                break;
            }
            else if(mid*mid < num){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
            mid = st + (end - st)/2;
        }
        return ans;
    }
};