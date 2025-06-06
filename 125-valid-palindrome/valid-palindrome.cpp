class Solution {
public:
    void convertLower(string &s){
        for(int i=0; i<s.length(); i++){
            if(isupper(s[i])){
                s[i] = tolower(s[i]);
            }
        }
    }

    bool isPalindrome(string s) {
        convertLower(s);

        string str;

        for(int i=0; i<s.length(); i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                str.push_back(s[i]);
            }
        }
        cout << "str : " << str;
        if(str.empty()) return true;

        int st = 0;
        int end = str.length()-1;

        while(st <= end){
            if(str[st] != str[end]){
                return false;
            }
            st++;
            end--;
        }
    return true;
    }
};