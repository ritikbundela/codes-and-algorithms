// Last updated: 26/11/2025, 22:33:31
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
    int solve(TreeNode* root, int &maxi){
        if (root == NULL) return 0;
        int leftMaxPath = max(0, solve(root->left, maxi));
        int rightMaxPath = max(0, solve(root->right, maxi));
        maxi = max(maxi, leftMaxPath + rightMaxPath + root->val);
        return max(leftMaxPath, rightMaxPath) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        solve(root,maxsum);
        return maxsum;
    }
};