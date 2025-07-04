class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
        
        // calculating row and col size
        int rowsize = heights.size();
        int colsize = heights[0].size();

        vector<vector<int>>dist(rowsize, vector<int>(colsize, 1e9));

        // i can go in 4 direction
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // maintian initail state
        pq.push({0, {0,0}});
        dist[0][0] = 0;

        // main logic
        while(!pq.empty()){
            auto frontNode = pq.top();
            pq.pop();

            int currabsDiff = frontNode.first;
            int r = frontNode.second.first;
            int c = frontNode.second.second;

            // check karlo kya me destination pe pouch gaya
            if(r == rowsize-1 && c == colsize-1) return dist[r][c];

            // me kha kha ja sakta hu
            for(int i=0; i<4; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];

                // check out of bound situation to nahi hai
                if(newr >= 0 && newr < rowsize && newc >=0 && newc < colsize){
                    // i am safe to go 
                    // now find curr dist
                    int newabsDiff = abs(heights[r][c]-heights[newr][newc]);
                    // find the max abs diff
                    int maxabsDiff = max(currabsDiff, newabsDiff);
                    // ab dist ko update karvao
                    if(maxabsDiff < dist[newr][newc]){
                        dist[newr][newc] = maxabsDiff;
                        pq.push({maxabsDiff, {newr,newc}});
                    } 
                }
            }
        }
        return 0;
    }
};