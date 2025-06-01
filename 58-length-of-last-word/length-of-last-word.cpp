class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=s.length()-1;
        // remove leading space from backword
        while(j >= 0 && s[j] == ' '){
            j--;
        }

        if(j < 0) return 0;

        string word;
        while(j >= 0 && s[j] != ' '){
            word.push_back(s[j]);
            j--;
        }
        return word.length();
    }
};