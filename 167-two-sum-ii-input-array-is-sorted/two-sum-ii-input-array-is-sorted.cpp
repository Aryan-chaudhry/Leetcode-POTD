class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;

        for(int i=0; i<numbers.size(); i++){
            int x = numbers[i];
            int y = target-x;

            if(mp.find(y) != mp.end()){
                return {mp[y]+1, i+1};
            }
            else{
                mp[x] = i;
            }
        }
        return {-1, -1};
    }
};