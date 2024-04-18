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
    TreeNode* dfs(TreeNode* root, int val, int depth, int curr){

        if(!root)
            return NULL;

        if(curr == depth-1){
            TreeNode* temp_left = root->left;
            TreeNode* temp_right = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = temp_left;
            root->right->right = temp_right;
            return root;
        }

        dfs(root->left, val, depth, curr+1);
        dfs(root->right, val, depth, curr+1);
        
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        return dfs(root, val, depth, 1);
    }
};