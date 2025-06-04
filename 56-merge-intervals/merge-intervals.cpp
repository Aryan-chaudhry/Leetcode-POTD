class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;

        for(auto temp : intervals){
            if(ans.empty()){
                ans.push_back(temp);
            }
            else{
                vector<int>&check = ans.back();
                if(check[1] >= temp[0]){
                    check[1] = max(check[1], temp[1]);
                }
                else{
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};