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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return 0;

        // both are on lhs
        if(p->val < root -> val && q -> val < root -> val){
            auto leftAns = lowestCommonAncestor(root -> left, p, q);
            if(leftAns != 0){
                return leftAns;
            }
        }
        else if(p->val > root -> val && q -> val > root -> val){
            auto rightAns = lowestCommonAncestor(root -> right, p, q);
            if(rightAns != 0){
                return rightAns;
            }
        }
       return root;
    }
};