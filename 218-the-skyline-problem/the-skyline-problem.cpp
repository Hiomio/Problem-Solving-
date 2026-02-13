class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>>events;
        for(auto& b : buildings)
        {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }
        sort(events.begin(), events.end(), [](pair<int , int>& a, pair<int, int>&b)
        {
            if(a.first != b.first) return a .first < b. first;
            return a.second < b.second;

        });
        multiset<int>heights = {0};
        int prev = 0;
        vector<vector<int>>result;

        for(auto& e : events)
        {
            int x = e.first, h = e.second;
                        if (h < 0) heights.insert(-h);
            else heights.erase(heights.find(h));
            
            int curMax = *heights.rbegin();
            if (curMax != prev) {
                result.push_back({x, curMax});
                prev = curMax;
            }
        }
        return result;
        }
};