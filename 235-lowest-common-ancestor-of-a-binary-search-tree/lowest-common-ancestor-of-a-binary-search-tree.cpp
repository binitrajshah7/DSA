/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        // Implies both target nodes exist in left subtree
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        // Both exist in right subtree
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        // Implies both are in left and right subtree so the current node is pivot and LCA
        return root;
    }
};