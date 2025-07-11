class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // remove duplicate
        unordered_set<int>st1;
        unordered_set<int>st2;

        for(auto no : nums1)
            st1.insert(no);

        for(auto no : nums2)
            st2.insert(no);
        
        // lets store our answer after processing
        vector<vector<int>>ans;
        vector<int>temp1;
        vector<int>temp2;

        for(auto no : st1){
            if(st2.find(no) == st2.end()){
                // not present
                // store in ans
                temp1.push_back(no);
            }
        }

        for(auto no : st2){
            if(st1.find(no) == st1.end()){
                // not present
                // store in answer
                temp2.push_back(no);
            }
        }

        // store in final answer
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};