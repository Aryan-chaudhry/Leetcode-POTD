class Solution {
public:
    bool solve(string &s, int i, string &p, int j, vector<vector<int>>&dp){
        // base cases
        if(i >= s.length() && j >= p.length()){
            // pattern matched
            return  true;
        }

        if(i <  s.length() && j >= p.length()){
            return false;
        }

        if(i >= s.length() && j < p.length()){
            // if rets of the char of p * than true otherwiise false;
            for(int k=j; k<p.length(); k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // mainlogic;
        bool ans;
        if(s[i] == p[j] || p[j] == '?'){
            ans =  solve(s, i+1, p, j+1, dp);
        }   
        else if(p[j] == '*'){
                bool ans1 = solve(s, i+1, p, j, dp);
                bool ans2 = solve(s, i, p, j+1, dp);
                ans = ans1 || ans2;
        }
        else{
            ans = false;
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, -1));
        return solve(s, 0, p, 0, dp);
    }
};