// Last updated: 26/11/2025, 22:33:52
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
    void check(TreeNode* p, TreeNode* q,bool &flag){
        if( p == NULL || q == NULL){
        if(p != q)
        flag = false;
        return;   
        }
        if(p->val != q->val)
        {
            flag = false;
            return ;
        }
        check(p->left, q->left,flag);
        check(p->right, q->right,flag);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
        check(p,q,flag);
        return flag;
    }
};