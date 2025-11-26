// Last updated: 26/11/2025, 22:31:38
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
    TreeNode* inorder(TreeNode* root, int val){
        if(root == NULL)
        return root;
        TreeNode* left = inorder(root->left,val);
        if (left != NULL) 
        return left;
        if(root->val == val)
        return root;
        return inorder(root->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = inorder(root,val);
        return ans;
    }
};