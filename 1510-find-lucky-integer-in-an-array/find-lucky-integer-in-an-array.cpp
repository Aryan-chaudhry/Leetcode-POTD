class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>freqMap;
        int maxNumber = INT_MIN;

        for(auto no : arr){
            freqMap[no]++;
        }

        for(auto &[no, freq] : freqMap){
            if(no == freq){
                maxNumber = max(maxNumber, no);
            }
        }
        return maxNumber == INT_MIN ? -1 : maxNumber;
    }
};