/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int, map<int, vector<int>>> mp;
        queue<pair<pair<int,int>, TreeNode*>> q;
        q.push(make_pair(make_pair(0,0),root));
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            int hd = front.first.first;
            int lvl = front.first.second;
            TreeNode* node = front.second;
            mp[hd][lvl].push_back(node->val);
            if(node->left) q.push(make_pair(make_pair(hd-1,lvl+1), node->left));
            if(node->right) q.push(make_pair(make_pair(hd+1,lvl+1), node->right));
        }
        for(auto it : mp) {
            vector<int> cpy;
            for(auto x : it.second) {
                sort(x.second.begin(), x.second.end());
                for(auto y : x.second) {
                    cpy.push_back(y);
                }
            }
            ans.push_back(cpy);
        }
        return ans;
    }
};
