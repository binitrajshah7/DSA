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
    TreeNode* build_tree_post(vector<int>& postorder, int post_start, int post_end, vector<int>& inorder, int in_start, int in_end, map<int, int>& inorder_mp) {
        if (post_start > post_end || in_start > in_end)
            return NULL;

        TreeNode* root = new TreeNode(postorder[post_end]);
        int in_root = inorder_mp[root->val];
        int numsLeft = in_root - in_start;

        root->left = build_tree_post(postorder, post_start, post_start + numsLeft - 1, inorder, in_start, in_root - 1, inorder_mp);
        root->right = build_tree_post(postorder, post_start + numsLeft, post_end - 1, inorder, in_root + 1, in_end, inorder_mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inorder_mp;
        for (int i = 0; i < inorder.size(); i++)
            inorder_mp[inorder[i]] = i;
        TreeNode* root = build_tree_post(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inorder_mp);
        return root;
    }

};