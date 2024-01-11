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
    void solve(TreeNode* root, int &result, int mini, int maxi){
        if(!root){
            result = max(result, abs(maxi - mini));
            return;
        }

        maxi = max(maxi, root->val);
        mini = min(mini, root->val);

        solve(root->left, result, mini, maxi);
        solve(root->right, result, mini, maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;

        int result = 0;
        solve(root, result, root->val, root->val);
        return result;
    }
};