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
    void solve(TreeNode* root, vector<int> &leaf_seq){
        if(!root){
            return;
        }

        if(!root->left && !root->right)
            leaf_seq.push_back(root->val);
        
        solve(root->left, leaf_seq); 
        solve(root->right, leaf_seq);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_seq_1;
        vector<int> leaf_seq_2;

        solve(root1, leaf_seq_1);
        solve(root2, leaf_seq_2);

        return leaf_seq_1 == leaf_seq_2;
    }
};