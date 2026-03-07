class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int>adj[n];
        vector<int> indegree(n, 0);
        vector<int>ans;
        for(auto x : a)
        {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int>q;
        for(int i = 0; i < n ; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto it = q.front();
            ans.push_back(it);
            q.pop();

            for(auto x : adj[it])
            {
                indegree[x]--;
                if(indegree[x] == 0)
                {
                    q.push(x);
                }
            }
        }
        return ans.size() == n;
    }
};