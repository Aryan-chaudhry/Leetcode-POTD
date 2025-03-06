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

    vector <vector<int>> graph;
    vector <bool> vis;
    int res = 0;
    void go(TreeNode* root){
        if(!root) return;

        int val = root->val;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        if(leftNode){
            int l = leftNode->val;
            graph[val].push_back(l);
            graph[l].push_back(val);
        }
        if(rightNode){
            int r = rightNode->val;
            graph[val].push_back(r);
            graph[r].push_back(val);
        }
        go(leftNode);
        go(rightNode);
    }
    void dfs(int node, int w){
        vis[node] = true;
        res = max(res, w);
        for(auto child: graph[node]){
            if(!vis[child]) 
                dfs(child, w + 1);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        graph.resize(1e5 + 7);
        vis.resize(1e5 + 7);
        go(root);
        dfs(start, 0);
        return res;
    }
};