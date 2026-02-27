class Solution {
public:
bool rotateString(string s, string goal) {
    if(s.size() != goal.size()) return false;
    int n = s.size();

    for(int i = 0; i < n; i++){
        int j;
        for(j = 0; j < n; j++){
            if(s[(i + j) % n] != goal[j])
                break;
        }
        if(j == n) return true;
    }
    return false;
}
};