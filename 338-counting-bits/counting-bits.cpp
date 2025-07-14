class Solution {
public:
    int no_of_1Bit(int num){
        int count = 0;
        while(num > 0){
            int bit = num%2;
            num /= 2;
            if(bit == 1){
                count++;
            }
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int>ans;

        for(int digit = 0; digit <= n; digit++){
            ans.push_back(no_of_1Bit(digit));
        }
        return ans;
    }
};