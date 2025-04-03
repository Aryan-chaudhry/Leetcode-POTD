class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int freq[10001]={0};

        for(int i=0; i<piles.size(); i++){
            freq[piles[i]]++;
        }

        for(int i=10000; i>0 && k>0; i--){

            while(freq[i]>0 && k>0){
                freq[i]--;
                freq[i-i/2]++;
                k--;
            }
        }

        int sum = 0;
        for(int i=0; i<10001; i++){
            if(freq[i] > 0){
                sum += (freq[i]*i);
            }
        }
        return sum;
    }
};