// Last updated: 26/11/2025, 22:33:54
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
    TreeNode *firstMistake=NULL, *secondMistake=NULL, *pre=new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(firstMistake->val, secondMistake->val);
    }

    void inorder(TreeNode* root){
        if(root == NULL)
        return ;

        inorder(root->left);

        if(firstMistake == NULL && root->val < pre->val){
            firstMistake = pre;
        }
        if(firstMistake != NULL && root->val < pre->val){
            secondMistake = root;
        }
        pre = root;

        inorder(root->right);
    }

};