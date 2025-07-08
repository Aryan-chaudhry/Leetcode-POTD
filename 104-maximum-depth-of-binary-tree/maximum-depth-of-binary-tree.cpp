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
    int solve(TreeNode* root){
        if(!root) return 0;

        int leftHeight = solve(root -> left);
        int rightHeight = solve(root -> right);

        int maxHeight = 1 + max(leftHeight, rightHeight);
        return maxHeight;
    }
    int maxDepth(TreeNode* root) {
        int depth = solve(root);
        return depth;
    }
};