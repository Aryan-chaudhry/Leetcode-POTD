class Solution {
public:
    bool solve(string &s, int i, string &t, int j){
        // base case
        if(i >= s.length() && j >= t.length()) return true;
        if(i < s.length() && j >= t.length()) return false;

        if(s[i] == t[j]){
            return solve(s, i+1, t, j+1);
        }
        else{
            return solve(s, i, t, j+1);
        }
    }
    bool isSubsequence(string s, string t) {
        return solve(s,0,t,0);
    }
};