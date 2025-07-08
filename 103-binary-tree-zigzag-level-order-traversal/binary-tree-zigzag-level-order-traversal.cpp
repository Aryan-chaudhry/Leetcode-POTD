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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>>ans;
        queue<TreeNode*>q;

        // maintain initail state
        q.push({root});
        bool isreverse = false;

        // main logic
        while(!q.empty()){
            int size  = q.size();
            vector<int>store;

            for(int i=0; i<size; i++){
                auto frontNode = q.front();
                q.pop();

                store.push_back(frontNode->val);

                if(frontNode -> left){
                    q.push(frontNode->left);
                }
                if(frontNode -> right){
                    q.push(frontNode->right);
                }
            }
            if(isreverse == true){
                reverse(store.begin(),store.end());
            }
            ans.push_back(store);
            // please make usre to toogle reverse condition
            isreverse = !isreverse;
        }
        return ans;
    }
};