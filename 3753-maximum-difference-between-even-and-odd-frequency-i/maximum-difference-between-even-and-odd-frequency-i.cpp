class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;

        for(auto ch : s){
            mp[ch]++;
        }

        int maxFreq = 0;
        int minFreq = INT_MAX;

        for(auto i : mp){
            if(i.second & 1){
                maxFreq = max(maxFreq, i.second);
            }
            else{
                minFreq = min(minFreq, i.second);
            }
        }
        return maxFreq - minFreq;
    }
};