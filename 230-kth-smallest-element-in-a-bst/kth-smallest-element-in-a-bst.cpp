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
    // As inorder traversal in BST is always sorted so follow same technique to keep space complexity optimised
    // Note: here count is passed by referenced
    void solve(TreeNode* root, int &count, int k, int &result){
        if(!root)   return;
        solve(root->left, count, k, result);
        // Node 1 will have 1 as count after left and right calls after call back goes to 2 with increased count as 2
        count++;
        if(count == k){
            result = root->val;
            return;
        }
        solve(root->right, count, k, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result;
        solve(root, count, k, result);
        return result;
    }
};