class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;

        for(int i=0; i<strs.size(); i++){
            string org = strs[i];
            string copy = org;
            sort(copy.begin(), copy.end());
            mp[copy].push_back(org);
        }

        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};