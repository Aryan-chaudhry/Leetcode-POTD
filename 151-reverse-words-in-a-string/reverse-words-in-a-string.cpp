class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int st = 0, end = 0;

        for(int i=0; i<s.length(); i++){
            // remove leading space
            while(i<s.length() && s[i] == ' '){
                i++;
            }

            // check out of bound
            if(i == s.length()){
                break;
            }

            // now main logic
            while(i < s.length() && s[i] != ' '){
                s[end++] = s[i++];
            }
            reverse(s.begin()+st, s.begin()+end);
            s[end++] = ' ';
            st = end;
        }
        s.resize(st-1);
        return s;
    }
};