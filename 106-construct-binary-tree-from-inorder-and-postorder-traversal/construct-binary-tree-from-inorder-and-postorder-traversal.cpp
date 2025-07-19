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
    int getIndex(vector<int>&inorder, int node){
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == node){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>&inorder, int inorderSt, int inorderEnd, vector<int>&postorder, int &postorderIndex){
        // base case 
        if(postorderIndex < 0) return 0;
        if(inorderSt > inorderEnd) return 0;

        // now fetch node from postorder
        int node = postorder[postorderIndex--];
        // find this node in inorder
        int index = getIndex(inorder, node);
        // now make root node
        TreeNode*root = new TreeNode(node);

        // now link the node
        /*
            in inorder we travese l-r
            than why we traverse here r-l
            because we traver in postorde from backword side
        */
        root -> right = solve(inorder, index+1, inorderEnd, postorder, postorderIndex);
        root -> left = solve(inorder, inorderSt, index-1, postorder, postorderIndex);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size()-1;

        int inorderSt = 0;
        int inorderEnd = inorder.size()-1;

        TreeNode* rootAns = solve(inorder, inorderSt, inorderEnd, postorder, postorderIndex);
        return rootAns;
    }
};