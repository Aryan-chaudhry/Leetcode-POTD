class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st = 0;
        int end = numbers.size()-1;

        while(st <= end){
            int sum = numbers[st] + numbers[end];
            if(sum > target){
                end--;
            }
            else if(sum < target){
                st++;
            }
            else{
                return {st+1, end+1};
            }
        }
        return {-1, -1};
    }
};