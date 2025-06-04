class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>str;

        int i=0;
        while(i < s.length()){
            string word;
            while(isalpha(s[i])){
                word.push_back(s[i]);
                i++;
            }
            str.push_back(word);
            while(s[i] == ' '){
                i++;
            }
        }

        for(auto word : str){
            cout << word << endl;
        }

        if(pattern.length() != str.size()) return false;

        unordered_map<char, string>mp;
        unordered_set<string>st;

        for(int i=0; i<pattern.length(); i++){
            if(mp.find(pattern[i]) != mp.end()){
                if(mp[pattern[i]] != str[i]){
                    return false;
                }
            }
            else{
                if(st.find(str[i]) != st.end()) return false;
                mp[pattern[i]] = str[i];
                st.insert({str[i]});
            }
        }
    return true;
    }
};