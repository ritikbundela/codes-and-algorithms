// Last updated: 26/11/2025, 22:32:07
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
        return NULL;

        if(root->val < key){
            root->right = deleteNode(root->right,key);
        }else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else{
            if(!root->left && !root->right ){
                delete root;
                return NULL;
            }
            else if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else{
                TreeNode* sucessor = root->right;
                while(sucessor->left)
                sucessor = sucessor->left;
                root->val = sucessor->val;
                root->right = deleteNode(root->right,sucessor->val);
                return root;
            }
        }
        return root;
    }
};