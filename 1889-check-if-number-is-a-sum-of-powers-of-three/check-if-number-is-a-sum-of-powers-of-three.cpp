class Solution {
public:
    bool checkPowersOfThree(int num) {
        while(num > 0){
            int rem = num%3;
            if(rem == 2) return false;
            num /= 3;
        }
        return true;
    }
};