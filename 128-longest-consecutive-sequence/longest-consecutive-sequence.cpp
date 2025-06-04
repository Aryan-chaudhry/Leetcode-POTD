class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;

        unordered_set<int>st;
        int longest = 1;
        int length = 1;

        for(auto no : nums){
            st.insert(no);
        }

        for(auto no : st){
            if(st.find(no-1) == st.end()){
                length = 1;
                int track = no;
                while(st.find(track+1) != st.end()){
                    length++;
                    track++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};