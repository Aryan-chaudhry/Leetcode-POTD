class Solution {
public:
    string reverseOnlyLetters(string s) {
        int st = 0;
        int end = s.length()-1;

        while(st <= end){
            if(isalpha(s[st]) && isalpha(s[end])){
                swap(s[st],s[end]);
                st++,end--;
            }
            else if(isalpha(s[st]) && !isalpha(s[end])){
                end--;
            }
            else{
                st++;
            }
        }
        return s;
    }
};