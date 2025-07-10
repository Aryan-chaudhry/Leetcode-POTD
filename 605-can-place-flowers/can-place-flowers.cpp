class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length = flowerbed.size();

        for(int i=0; i<length; i++){
            bool left = i == 0 || flowerbed[i-1] == 0;
            bool right = i == length-1 || flowerbed[i+1] == 0;

            if(left && flowerbed[i] == 0 && right){
                flowerbed[i] = 1;
                n--;
            }
        }
        return n<=0;
    }
};