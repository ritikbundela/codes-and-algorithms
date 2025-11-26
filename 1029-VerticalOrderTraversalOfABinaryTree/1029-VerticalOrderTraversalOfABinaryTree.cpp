// Last updated: 26/11/2025, 22:31:20
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
    void preorder(TreeNode* root,int vertical,int level,map<int,map<int,multiset<int>>>&nodes){
        if(root == NULL)
        return ;
        nodes[vertical][level].insert(root->val);
        preorder(root->left,vertical-1,level+1,nodes);
        preorder(root->right,vertical+1,level+1,nodes);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>>nodes;
        preorder(root,0,0,nodes);
           for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        }
};