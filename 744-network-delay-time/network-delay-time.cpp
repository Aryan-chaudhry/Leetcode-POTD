class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // make graph
        unordered_map<int, list< pair<int,int> > >adj;

        for(int i=0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        // make time vector
        vector<int>time(n+1, 1e9);
        queue<int>q; // --> u, v, wt

        // maintian initial state
        time[k] = 0;
        q.push(k);

        // Main logic

        while(!q.empty()){
            int U = q.front();
            q.pop();

            for(auto nbr : adj[U]){
                int V = nbr.first;
                int wt = nbr.second;

                if(time[U] + wt < time[V]){
                    time[V] = time[U] + wt;
                    q.push(V);
                }
            }
        }

        int maxi = INT_MIN;
        for(int i=1; i<time.size(); i++){
            maxi = max(maxi, time[i]);
        }
        return maxi == 1e9 ? -1 : maxi;
    }
};