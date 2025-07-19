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
    int findNode(vector<int>&inorder, int &Node){
        int index = -1;

        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == Node){
                index = i;
                break;
            }
        }
        return index;
    }

    TreeNode* solve(vector<int>& preorder, int &preorderIndex, vector<int>& inorder, int inorderSt, int inorderEnd){
        // base cases
        if(preorderIndex >= preorder.size()) return nullptr;
        if(inorderSt > inorderEnd) return nullptr;

        // find the preorder node in inorder;
        int Node = preorder[preorderIndex];
        preorderIndex++;
        int index = findNode(inorder, Node);

        // now create root;
        TreeNode*root = new TreeNode(Node);

        // make a tree
        root -> left = solve(preorder, preorderIndex, inorder, inorderSt, index-1);
        root -> right = solve(preorder, preorderIndex, inorder, index+1, inorderEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        int inorderSt = 0;
        int inorderEnd = inorder.size()-1;

        TreeNode* rootAns = solve(preorder, preorderIndex, inorder, inorderSt, inorderEnd);
        return rootAns;
    }
};