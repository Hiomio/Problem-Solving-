class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        //first occurence
        int l = 0;
         int r=n-1;
        int first = -1;
        
        while(l<=r) {
            int m = l + (r - l) / 2;
            if (target == nums[m]) first = m;
            if (target <= nums[m]) {
                r = m - 1;
            } else l = m + 1;

            }
        
        //last occurence
        l = 0;
        r = n - 1;
        int last = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (target == nums[m]) last = m;

            if (target >= nums[m]) {
                l = m + 1;
            } else r = m - 1;
        }

        return vector<int> {first, last};

    }
};