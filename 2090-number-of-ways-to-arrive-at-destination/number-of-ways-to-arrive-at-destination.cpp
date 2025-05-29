class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Use long long to prevent overflow
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        int mod = 1e9 + 7;

        // Min-heap: {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [dst, node] = pq.top();
            pq.pop();

            if (dst > dist[node]) continue;

            for (auto [adjNode, wt] : adj[node]) {
                long long newDist = dst + wt;

                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node];
                    pq.push({newDist, adjNode});
                } else if (newDist == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
