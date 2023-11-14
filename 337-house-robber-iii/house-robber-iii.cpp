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
    // Intuition: Same problem as house robber 1  and 2 where at every point we will have 2 options either to pick or not pick
    // So we store both values in our return statement in pair i.e {pick, not_pick}

    // Post Order Tree traversal where we get {pick, not_pick} values from both childrens
    // and for current root we will have two options again 
    pair<int, int> solve(TreeNode* root){
        if(!root)
            return {0, 0};

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        // if pick then we add root->val and take non pick value from both childrens
        int pick = root->val + left.second + right.second;
        // if not_pick we don't consider root->val and take maximum of pick and not_pick from both childrens
        // if not_pick then our children node is free so we take max of both values from both ends
        int not_pick = max(left.first, left.second) + max(right.first, right.second);
        return {pick, not_pick};
    }

    int rob(TreeNode* root) {
       pair<int, int> result = solve(root);
       // we return max of both pick and not_pick case
       return max(result.first, result.second); 
    }
};