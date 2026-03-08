class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        /*Build a Adjacency List*/
        vector<pair<int, int>>adj[n];
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        /*Initialize distance array and queue*/
        vector<int>dist(n, 1e9);
        queue<pair<int, pair<int, int>>>q; /*{src, {node , cost}}*/
        dist[src] = 0;
        q.push({0, {src , 0}});
        /*BFS*/
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;  // Edge weight (price)

                if(cost + edW < dist[adjNode] && stops <= k )
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});

                }
            }
        }

        if(dist[dst] == 1e9) return -1;  // Unreachable within K stops
        return dist[dst];

    }
};