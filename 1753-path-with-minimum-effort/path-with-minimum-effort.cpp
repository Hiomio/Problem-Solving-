class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //{diff, {row,col}}
        //datatype, vector<datatype>, greater<datatype>
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        //effort is max. difference in the path
        vector<vector<int>> diff(n, vector<int>(m, INT_MAX));
        diff[0][0]= 0;
        pq.push({0,{0,0}});
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int effort= it.first;
            int row= it.second.first;
            int col= it.second.second;
            //will check for the last {row, col} and we will return the effort till this here.
            //how can we be sure this is the answer? That's because of the priority queue(min heap)
            //since it will have the lowest one(effort) on the top so it is a guarantee that we have got the minimum effort till this node
            if(row == n-1 && col == m-1){
                return effort;
            }

            for(int i=0; i<4; i++){
                int nrow= row+dr[i];
                int ncol= col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){//checks for the validity of the coordinates
                    int neweff= max(abs(heights[row][col]-heights[nrow][ncol]), effort);//self-explainatory
                    if(neweff < diff[nrow][ncol]){
                        diff[nrow][ncol]= neweff;
                        pq.push({neweff, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};