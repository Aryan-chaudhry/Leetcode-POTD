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
    void fillAdj(TreeNode* root, unordered_map<int,list<int>>&adj){
        if(!root) return;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            if(frontNode->left){
                adj[frontNode->val].push_back(frontNode->left->val);
                adj[frontNode->left->val].push_back(frontNode->val);
                q.push(frontNode->left);
            }
            if(frontNode->right){
                adj[frontNode->val].push_back(frontNode->right->val);
                adj[frontNode->right->val].push_back(frontNode->val);
                q.push(frontNode->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,list<int>>adj;
        fillAdj(root, adj);

        vector<int>ans;
        queue<pair<int,int>>q;
        unordered_map<int,bool>visited;

        q.push({target->val, 0});
        visited[target->val] = true;

        // main logic
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            int node = frontNode.first;
            int step = frontNode.second;
            if(step == k){
                ans.push_back(node);
            }

            for(auto nbr : adj[node]){
                if(!visited[nbr]){
                    q.push({nbr,step+1});
                    visited[nbr] = true;
                }
            }
        }
        return ans;
    }
};