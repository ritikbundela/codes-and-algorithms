// Last updated: 26/11/2025, 22:32:40
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
    void solve(TreeNode* root, int &total){
        if(root == NULL)
        return ;
        total++;
        solve(root->left,total);
        solve(root->right,total);
    }
    int countNodes(TreeNode* root) {
        if(root == NULL)
        return 0;
        int total = 0;
        solve(root,total);
        return total;
    }
};