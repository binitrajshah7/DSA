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
        // base case
        if(!root) 
            return nullptr;
        // if we find any of our target node then we return the target node
        if(root == p || root == q) 
            return root;
        // we keep traversing
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // if we find both our target from left and right subtree that implies it is our answer so we return
        if(left && right)
            return root;
        // else we return whatever we get from our child nodes
        else if(!left)
            return right;
        else
            return left;

    }
};