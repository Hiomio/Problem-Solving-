class Solution {
public:
bool change(string a,string b){
    int cnt=0;
    for(int i=0;i<a.size();i++) if(a[i]!=b[i]) cnt++;
    return cnt<=2;
}
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> ans;
        int n=q.size();
        int m=d.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(change(q[i],d[j])) {
                    ans.push_back(q[i]);
                    break;}
            }
        }
        
        return ans;
    }
};