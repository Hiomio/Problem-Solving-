/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // TreeNode* targetNode = nullptr;
        
        // step-1: capture parent of each node using BFS
        unordered_map<TreeNode*, TreeNode*> parent;
        
        queue<TreeNode*> q;
        if(root){
            q.push(root);
            parent[root] = nullptr;
        }

        while(q.size()){
            TreeNode* node = q.front(); q.pop();

            // if(!targetNode && node->val == target) targetNode = node;           // find target node on-the-fly... along with finding parent

            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }
        }


        // step-2: find all nodes at dist k using BFS
        unordered_set<TreeNode*> visited;                           // keep track of nodes considered to avoid circular loop
        q.push(target);

        while(k){                                                   // dist k can be thought as level starting from 0. Means when k is 0, we have reached at required level
            int nodeCount = q.size();

            while(nodeCount--){
                TreeNode* node = q.front(); q.pop();
                visited.insert(node);

                if(parent[node] && !visited.count(parent[node]))      // parent doesn't exist only for root node
                    q.push(parent[node]);

                if(node->left && !visited.count(node->left)) 
                    q.push(node->left);
                    
                if(node->right && !visited.count(node->right))
                    q.push(node->right);
            }

            --k;
        }

        
        // step-3: extract result
        vector<int> res;
        for(; q.size(); q.pop())
            res.push_back(q.front()->val);

        return res;
    }
};