// Last updated: 26/11/2025, 22:33:51
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
    void check(TreeNode* left, TreeNode* right,bool &flag){
        if(!left || !right)
        {
            if(left != right)
            flag = false;
            return ;
        }
        if(left->val != right->val){
        flag = false;
        return ;
        }
        check(left->left,right->right,flag);
        check(left->right,right->left,flag);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || root->left == NULL and root->right == NULL)
        return true;
        bool flag = true;
        check(root->left ,root->right,flag);
        return flag;
    }
};