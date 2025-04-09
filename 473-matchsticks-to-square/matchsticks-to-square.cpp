class Solution {
public:
    bool solve(vector<int>&matchsticks, vector<int>&sides, int i){
        if(i == matchsticks.size()) // all match sticks are tried
            return sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0;
        
        bool ans = false;
        // ith matchstick cab be a part of A, B, C or D
        for(int j=0; j<sides.size(); j++){
            if(matchsticks[i] <= sides[j]){
                sides[j]-=matchsticks[i]; // include
                ans = ans || solve(matchsticks, sides, i+1);
                if(ans == true) return true;
                sides[j] += matchsticks[i];
            }
        }
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(matchsticks.size() < 4) return false;
        if(sum%4 != 0) return false;

        int sideSum = sum/4;

        vector<int>sides(4, sideSum); // 0->A side sum
                                        // 1 -> B side sum and so on

        // sort in decreasing order to escape in extra recursive call
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        return solve(matchsticks, sides, 0);
    }
};