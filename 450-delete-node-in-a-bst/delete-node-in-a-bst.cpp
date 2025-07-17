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
    int findMax(TreeNode* root){
        if(!root) return -1;

        while(root -> right){
            root = root -> right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(root -> val == key){
            // es key ko delete karna hai
            // 4 case

            // case 1 --> 0 child
            if(!root -> left && !root -> right){
                delete(root);
                return 0;
            }
            
            // case 2 --> only left child
            if(root -> left && !root -> right){
                TreeNode*ans = root -> left;
                root -> left = 0;
                delete(root);
                return ans;
            }

            // case 3 --> only right child
            if(!root -> left && root -> right){
                TreeNode*ans = root -> right;
                root -> right = 0;
                delete(root);
                return ans;
            }

            // case 4 both child
            if(root -> left && root -> right){
                // find just smaller value than that
                int maxValue = findMax(root -> left);
                // replace this value of root -> val
                root -> val = maxValue;
                // delete this maxvalue where it is actually present
                root -> left = deleteNode(root -> left, maxValue);
                return root;
            }
        }
        else if(key < root -> val){
            root -> left = deleteNode(root -> left, key);
        }
        else{
            root -> right = deleteNode(root -> right, key);
        }
        return root;
    }
};