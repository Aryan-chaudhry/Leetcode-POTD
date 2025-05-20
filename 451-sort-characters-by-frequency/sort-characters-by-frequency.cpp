class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>>store;
        unordered_map<char,int>mp;
        string ans = "";

        for(auto ch : s){
            mp[ch]++;
        }

        for(auto i : mp){
            pair<int,char>p;
            p.first = i.second;
            p.second = i.first;
            store.push_back(p);
        }

        sort(store.rbegin(), store.rend());

        for(auto p : store){
            while(p.first--){
                ans += p.second;
            }
        }
        return ans;
    }    
};