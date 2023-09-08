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
    bool check_symmetric(TreeNode* left, TreeNode* right){
        // if any of the node is null then we check if both is null or not if both null we return true else false
        if(!left || !right)
            return left == right;
        // if left value and right value are not same i.e node of mirror
        if(left->val != right->val)
            return false;

        // else we check if both left child or left and right child of right are same or not further
        // and right child of left is equal to left child of right or not and if we get true from both sides
        // we return true
        return check_symmetric(left->left, right->right) && check_symmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check_symmetric(root->left, root->right);
    }
};