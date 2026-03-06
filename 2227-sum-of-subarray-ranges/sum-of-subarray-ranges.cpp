class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long minSum = 0, maxSum = 0;
        stack<int> st;

        // ----- Sum of subarray minimums -----
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] > nums[i])){
                int mid = st.top(); 
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                long long count = (long long)(mid - left) * (right - mid);
                minSum += count * nums[mid];
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // ----- Sum of subarray maximums -----
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] < nums[i])){
                int mid = st.top(); 
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                long long count = (long long)(mid - left) * (right - mid);
                maxSum += count * nums[mid];
            }
            st.push(i);
        }

        return maxSum - minSum;
    }
};