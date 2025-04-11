class Solution {
public:
    void countArrangement(vector<int>&v, int&n, int&ans, int currNum){
        // base case
        if(currNum == n+1){
            ++ans;
            return;
        }

        for(int i=1; i<=n; ++i){
            if(v[i] == 0 && (currNum%i == 0 || i%currNum == 0)){
                // i can place
                v[i] = currNum;
                countArrangement(v, n, ans, currNum+1);
                v[i] = 0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>v(n+1); // 1 based indexing
        int ans = 0;
        countArrangement(v, n, ans, 1);
        return ans;
    }
};