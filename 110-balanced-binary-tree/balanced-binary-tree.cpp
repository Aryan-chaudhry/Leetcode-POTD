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
    int getHeight(TreeNode* root){
        if(!root) return 0;

        int leftHeight = getHeight(root -> left);
        int rightHeight = getHeight(root -> right);
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        bool opt1 = isBalanced(root -> left);
        bool opt2 = isBalanced(root -> right);
        int leftHeight = getHeight(root -> left);
        int rightHeight = getHeight(root -> right);
        int absDiff = abs(leftHeight-rightHeight);
        bool status = absDiff <= 1 ? true : false;

        if(opt1 && opt2 && status) return true;
        return false;
    }
};