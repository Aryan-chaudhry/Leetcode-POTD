class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // lets build adjacency list
        unordered_map<int, list<pair<int,int>>>graph;

        for(auto &flight : flights){
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        // priority queue to select the next city with minimum cost
        // each element would be {cost so far, current city, stops so far}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;

        pq.push({0, src, 0});

         vector<int>visited(n, 1e9);
         visited[src] = true;

        // array to keep track of minimum number of stops to reach each city
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0];
            int city = curr[1];
            int stops = curr[2];

            if(city == dst) return cost;
            // if stops exceeds k than 
            if(stops > k) continue;

            // if we have already visited the city with less stops fewer stope
            // so skip this path

            if(visited[city] < stops) continue;
            // update the miinum stops for the curr sity

            visited[city] = min(visited[city], stops);

            // explore all neighbour cities

            for(auto nbr : graph[city]){
                int nextCity = nbr.first;
                int price = nbr.second;
                pq.push({cost+price, nextCity, stops+1}); 
            }
        }

        return -1;
    }
};