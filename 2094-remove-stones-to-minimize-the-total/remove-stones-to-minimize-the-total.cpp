class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int>pq;
        int sum = 0;

        for(int i=0; i<n; i++){
            pq.push(piles[i]);
        }

        while(k--){
            int maxi = pq.top();
            pq.pop();
            maxi = (maxi - maxi/2);
            pq.push(maxi);
        }

        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};