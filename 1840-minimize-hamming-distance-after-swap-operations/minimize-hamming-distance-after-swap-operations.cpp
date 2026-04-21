class UnionFind{
public:
    vector<int> parent, rank;
    UnionFind(int n){
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int x){
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }
    void unite(int x, int y){
        int px = findParent(x);
        int py = findParent(y);
        if(px == py) return;

        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;

        if(rank[px] == rank[py]) rank[px]++;
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        UnionFind uf(n);

        for(auto &swap: allowedSwaps){
            uf.unite(swap[0], swap[1]);
        }
        vector<vector<int>> group(n);
        for(int i = 0; i<n; i++) group[uf.findParent(i)].push_back(i);

        int matches = 0;
        unordered_map<int, int> freq;
        for(int i = 0; i<n; i++){
            if(group[i].empty()) continue;
            freq.clear();
            for(int ind : group[i])
                freq[source[ind]]++;
            for(int ind: group[i]){
                if(freq[target[ind]] > 0){
                    freq[target[ind]]--;
                    matches++;
                }
            }
        }
        return n - matches;
    }
};