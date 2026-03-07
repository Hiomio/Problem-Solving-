class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int  n  = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1])
        {
            return -1;
        }
        queue<pair<int, pair<int, int>>>q;
        q.push({0,{0,0}});
        vector<vector<int>> distance(n, vector<int> (n, INT_MAX));
        distance[0][0] = 0 ;
        vector<int> dx  = { -1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!q.empty())
        {
            auto it  = q.front();
            q.pop();
            int dist  = it.first;
            int x  = it.second.first;
            int y = it.second.second;
            for(int i =0; i<8; i++)
            {
                int newX = x +  dx[i];
                int newY =  y  + dy[i];
                if(newX >= 0 && newX <n && newY >=0 && newY <n && grid[newX][newY] == 0 && dist + 1 < distance[newX][newY])
                {
                    distance[newX][newY] = dist + 1;
                    q.push({ 1 + dist, {newX, newY}});
                }
            }
        }
        return distance[n-1][n-1] == INT_MAX ? -1: distance[n-1][n-1] + 1;
    }
};