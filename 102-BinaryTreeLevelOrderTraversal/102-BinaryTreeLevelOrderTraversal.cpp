// Last updated: 26/11/2025, 22:33:50
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
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>>ans;
       queue<TreeNode*>q;
       if(root)
       q.push(root);
       while(!q.empty()){
        vector<int>temp;
        int size = q.size();
        for(int i=0; i<size; i++){
        TreeNode* nd = q.front();
        if(nd->left)
        q.push(nd->left);
        if(nd->right)
        q.push(nd->right);
        temp.push_back(nd->val);
        q.pop();
        }
        ans.push_back(temp);
       }
       return ans;
    }
};