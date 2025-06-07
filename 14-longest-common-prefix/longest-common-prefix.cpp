class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";

        string check = strs[0];
        bool bound = true;

        for(int i=0; i<check.length(); i++){
            char ch = check[i];

            for(int j=1; j<strs.size(); j++){
                string curr = strs[j];

                if(i < curr.length()){
                    if(ch != curr[i]){
                        return prefix;
                    }
                }
                else{
                    bound = false;
                }
            }
            if(bound == true) prefix.push_back(ch);
        }
        return prefix;
    }
};