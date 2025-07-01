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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;

        // maintain initial state
        q.push(root);
        bool isNullFound = false;

        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            if(frontNode == nullptr){
                isNullFound = true;
            }
            else{
                if(isNullFound == true){
                    return false;
                }
                q.push(frontNode -> left);
                q.push(frontNode -> right);
            }
        }
        return true;
    }
};