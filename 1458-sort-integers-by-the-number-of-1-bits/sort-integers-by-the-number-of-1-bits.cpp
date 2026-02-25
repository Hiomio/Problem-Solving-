class Solution {
public:
    int count_bits(int n ){
        int i = 0 ;
        while(n){
            i += (n & 1);
            n = (n >> 1);
        }
        return i;
    }

    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;

        for(int i = 0; i <= 32; i++){
            vector<int> sub;
            for(int j = 0; j < n; j++){
                if(count_bits(arr[j]) == i){
                    sub.push_back(arr[j]);
                }
            }
            sort(sub.begin(), sub.end());
            for(int& x : sub){
                ans.push_back(x);
            }
        }
        return ans;
    }
};