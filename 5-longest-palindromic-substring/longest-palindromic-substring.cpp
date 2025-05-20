class Solution {
public:
    bool isPalindrome(string &s, int st, int end){
        while(st <= end){
            if(s[st] != s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int longest = 0;
        int index = -1;

        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(isPalindrome(s,i,j)){
                    if(j-i+1 > longest){
                        longest = j-i+1;
                        index = i;
                    }
                }
            }
        }
        return s.substr(index, longest);
    }
};