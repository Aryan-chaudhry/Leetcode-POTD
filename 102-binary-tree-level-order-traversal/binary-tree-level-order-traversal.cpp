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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>>ans;
        queue<TreeNode*>q;

        // maintain initial state
        q.push(root);

        // main logic

        while(!q.empty()){
            int size = q.size();
            vector<int>temp;

            for(int i=0; i<size; i++){
                auto frontNode = q.front();
                q.pop();
                temp.push_back(frontNode->val);

                if(frontNode -> left){
                    q.push(frontNode->left);
                }
                if(frontNode -> right){
                    q.push(frontNode->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};