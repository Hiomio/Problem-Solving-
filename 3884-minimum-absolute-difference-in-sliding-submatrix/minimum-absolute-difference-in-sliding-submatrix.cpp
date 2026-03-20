class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {

                set<int> values;

                // Collect values in k x k submatrix
                for (int x = i; x < i + k; ++x) {
                    for (int y = j; y < j + k; ++y) {
                        values.insert(grid[x][y]);
                    }
                }

                // If all values are same
                if (values.size() == 1) {
                    ans[i][j] = 0;
                    continue;
                }

                int prev = -1e6;
                int minDiff = INT_MAX;

                for (int val : values) {
                    if (prev != -1e6) {
                        minDiff = min(minDiff, abs(val - prev));
                    }
                    prev = val;
                }

                ans[i][j] = minDiff;
            }
        }

        return ans;
    }
};