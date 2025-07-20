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
    void solve(TreeNode* root, vector<int>&ans){
        if(!root) return;

        solve(root -> left, ans);
        ans.push_back(root -> val);
        solve(root -> right, ans);
    }
    
    int bruteForce(TreeNode* root, int k){
        vector<int>ans;
        solve(root, ans);
        return ans[k-1];
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int ans = bruteForce(root, k);
        return ans;
    }
};