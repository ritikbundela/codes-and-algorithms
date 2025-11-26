// Last updated: 26/11/2025, 22:31:16
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
    TreeNode* construct(vector<int>&preorder, int &index, long min, long max,int size){
        if (index >= size) 
        return NULL;

    int val = preorder[index];

    // Ensure the current value is within range
    if (val <= min || val >= max) 
        return NULL;

    // Create the node and move to the next index
    TreeNode* root = new TreeNode(val);
    index++;

    // Construct the left and right subtrees
    root->left = construct(preorder, index, min, val, size);
    root->right = construct(preorder, index, val, max, size);

    return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return construct(preorder,index,INT_MIN,INT_MAX,preorder.size());
    }
};