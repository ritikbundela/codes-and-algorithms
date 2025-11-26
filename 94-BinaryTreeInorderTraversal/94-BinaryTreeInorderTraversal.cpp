// Last updated: 26/11/2025, 22:33:57
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* current = root;

        while (current) {
            if (!current->left) {
                res.push_back(current->val); 
                current = current->right;
            } else {
                TreeNode* pred = current->left;
                while (pred->right && pred->right != current) {
                    pred = pred->right;
                }

                if (!pred->right) {
                    pred->right = current; 
                    current = current->left;
                } else {
                    pred->right = NULL;      
                    res.push_back(current->val); 
                    current = current->right;
                }
            }
        }

        return res;
    }
};