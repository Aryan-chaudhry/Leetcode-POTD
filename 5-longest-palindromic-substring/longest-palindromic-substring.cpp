class Solution {
public:
    int expandAroundCentre(string s, int st, int end){
        
        while(st >= 0 && end < s.length() && s[st] == s[end]){
            st--;
            end++;
        }
        return end-st-1;
    }

    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int st = 0, end = 0;

        for(int i=0; i<s.length(); i++){
            int len1 = expandAroundCentre(s,i,i); // find all palindrom sybstring of odd length
            int len2 = expandAroundCentre(s,i,i+1); // of even 
            int maxLen = max(len1,len2);

            if(maxLen > end - st){
                st = i-(maxLen-1)/2;
                end = i+(maxLen)/2;
            }
        }
        return s.substr(st,end-st+1);
    }
};