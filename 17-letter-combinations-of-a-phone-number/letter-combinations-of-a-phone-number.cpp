class Solution {
public:

    void solve(string &digit, int index, string str, vector<string>&ans,unordered_map<char,string>&mp ){

        // base case 
        if(index >= digit.length()){
            if(str.length() > 0){
                ans.push_back(str);
            }
            return;
        }

        string track = mp[digit[index]];

        for(auto ch : track){
            str.push_back(ch);
            solve(digit, index+1, str, ans, mp);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string>ans;
        string str = "";
        int index = 0;

        solve(digits, index, str, ans, mp);
        return ans;
    }
};