// Last updated: 26/11/2025, 22:32:49
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
    void solve(TreeNode* root,int level,map<int,int>&mp)
    {
        if(root == NULL)
        return ;
        if(mp.find(level) == mp.end()){
            mp[level] = root->val;
        }
        solve(root->right,level+1,mp);
        solve(root->left,level+1,mp);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
        return {};
        vector<int>ans;
        map<int,int>mp;
        solve(root,0,mp);
        for(auto x:mp)
        ans.push_back(x.second);
        return ans;
    }
};