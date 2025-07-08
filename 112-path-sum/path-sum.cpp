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
    bool solve(TreeNode*root, int sum, int targetSum){
        if(!root) return false;

        sum += root->val;

        if(!root -> left && !root -> right){
            if(sum == targetSum) return true;
            return false;
        }

        bool leftAns =  solve(root -> left, sum, targetSum);
        bool rightAns =  solve(root -> right, sum, targetSum);

        return leftAns || rightAns;
        

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = solve(root, sum, targetSum);
        return ans;
    }
};