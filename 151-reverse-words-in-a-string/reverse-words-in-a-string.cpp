class Solution {
public:
    string reverseWords(string s) {
        // step 1
        // reverse whole string
        reverse(s.begin(), s.end());

        int st = 0, end = 0;

        for(int i=0; i<s.length(); i++){
            // step 2 skip leading zero
            while(i < s.length() && s[i] == ' '){
                i++;
            }
            // out of bound check
            if(i == s.length()){
                break;
            }

            // step 3
            // copy char to right position
            while( i < s.length() && s[i] != ' '){
                s[end++] = s[i++];
            }
            // step 4 --> reverse individual word
            reverse(s.begin()+st, s.begin()+end);
            // step 5 --> add space between word
            s[end++] = ' ';
            st = end;
        }
        // resize final string
        s.resize(st-1);
        return s;
    }
};