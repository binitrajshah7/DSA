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
    int get_max_path_sum(TreeNode* root, int &maxi){
        if(!root)
            return 0;
        int left_sum = max(0, get_max_path_sum(root->left, maxi));
        int right_sum = max(0, get_max_path_sum(root->right, maxi));
        // We are storing maximum for every curve here
        maxi = max(maxi, left_sum + right_sum + root->val);
        // we are considering only those path from left or right which gives us maximum
        // we ignore other paths
        return root->val + max(left_sum, right_sum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        get_max_path_sum(root, maxi);
        return maxi;
    }
};