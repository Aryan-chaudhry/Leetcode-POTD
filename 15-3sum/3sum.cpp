class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>s;

        for(int i=0; i<nums.size(); i++){
            int st = i+1;
            int end = nums.size()-1;

            while(st < end){

                int sum = nums[i] + nums[st] + nums[end];

                if(sum == 0){
                    s.insert({ nums[i], nums[st], nums[end] });
                    st++;
                    end--;
                }
                else if(sum > 0){
                    end--;
                }
                else{
                    st++;
                }
            }
        }

        for(auto trp : s){
            ans.push_back(trp);
        }
        return ans;
    }
};