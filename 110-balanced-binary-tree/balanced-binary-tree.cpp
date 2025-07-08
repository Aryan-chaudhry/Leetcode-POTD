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
    int getHeight(TreeNode*root){
        if(!root) return 0;

        int left = getHeight(root -> left);
        int right = getHeight(root -> right);
        int maxHeight = 1 + max(left,right);
        return maxHeight;
        
    }
    bool isBalanced(TreeNode* root) {
        // har ek node pe jakar uski height nikal lo agar height ka diff > 1 aaya to 
        // balance nahi hai
        if(!root) return true;
        

        int leftHeight = getHeight(root -> left);
        int rightHeight = getHeight(root -> right);
        int absDiff = abs(leftHeight-rightHeight);
        bool status = absDiff <= 1 ? true : false;

        int leftBalanced = isBalanced(root -> left);
        int rightBalanced = isBalanced(root -> right);

        if(status && leftBalanced && rightBalanced) return true;
        return false;


        
    }
};