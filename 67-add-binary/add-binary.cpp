class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int n1 = a.size(), n2 = b.size();
        string ans = "";
        while(n1 > 0 || n2 > 0 || carry) {
            int bit1 = (n1 > 0) ? a[n1-1]-'0' : 0;
            int bit2 = (n2 > 0) ? b[n2-1]-'0' : 0;

            int sum = bit1 + bit2 + carry;
            ans += (sum % 2) + '0';
            carry = sum / 2;

            n1--; n2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};