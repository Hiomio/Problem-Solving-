class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        char last = s[0];
        int count = 0;
        int count1 = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i] == last){
                count1 ++;
            }else{
                ans += min(count,count1);
                count = count1;
                count1 = 1;
                last = s[i];
            }
        }
        ans += min(count,count1);
        return ans;
    }
};