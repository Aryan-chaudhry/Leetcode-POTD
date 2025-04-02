class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char, int>mp;

        int no = 26;
        for(char ch = 'a'; ch <= 'z'; ch++){
            mp[ch] = no;
            no--;
        }

        int sum = 0;

        for(int i=0; i<s.length(); i++){
            sum += mp[s[i]] * (i+1);
        }
        return sum;
    }
};