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
    void solve(TreeNode* root, int curr, int &result){
        if(!root){
            return;
        }

        curr = curr*10 + root->val;

        if(!root->right && !root->left){
            result += curr;
            return;
        }

        solve(root->left, curr, result);
        solve(root->right, curr, result);
    }

    int sumNumbers(TreeNode* root) {
        int result = 0;
        solve(root, 0, result);
        return result;
    }
};