class Solution {
public:
    bool isVowel(char &ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'I' || ch == 'E' || ch == 'O' || ch == 'U';
    }
    string reverseVowels(string s) {
        int st = 0;
        int end = s.length()-1;

        while(st <= end){
            if(isVowel(s[st]) && isVowel(s[end])){
                swap(s[st++], s[end--]);
            }
            else if(!isVowel(s[st]) && isVowel(s[end])){
                st++;
            }
            else if(isVowel(s[st]) && ! isVowel(s[end])){
                end--;
            }
            else{
                st++;
                end--;
            }
        }
        return s;
    }
};