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
    int res = 0;
    int infected(TreeNode* root, int start, int &dist){
        if(root == NULL)
        return 0;


        int ldist = -1,rdist = -1;

        int lh = infected(root->left, start, ldist);
        int rh = infected(root->right, start, rdist);

        if(root->val == start)
        {
            int temp = max(lh,rh);
            res = max(res,temp);
            dist = 0; return 1;
        }

        if(ldist != -1){
            dist = lh;
            res = max(res, dist+rh);
            return lh+1;
        }
        else if(rdist != -1){
            dist = rh;
            res =max(res, dist+lh);
            return rh+1;
        }

        return max(lh,rh)+1;
    }
    int amountOfTime(TreeNode* root, int start) {
        int dist = 0;
        int ans = infected(root, start, dist);

        return res;
        
    }
};