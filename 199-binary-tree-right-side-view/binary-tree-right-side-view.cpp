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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;

        if(!root) return ans;
        if(!root -> left && !root -> right){
            ans.push_back(root -> val);
            return ans;
        }

        queue<TreeNode*>q;


        // maintain initial state
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int rightView = 0;

            for(int i=0; i<size; i++){
                auto frontNode = q.front();
                q.pop();
                
                if(frontNode != 0){
                    rightView = frontNode -> val;
                }

                if(frontNode -> left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            ans.push_back(rightView);
        }
        return ans;
    }
};