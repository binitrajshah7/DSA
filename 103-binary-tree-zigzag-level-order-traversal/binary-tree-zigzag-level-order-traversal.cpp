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
    // Intuition: We just keep a flag for every level if flag left to right is true then we simply push it to our row or level
    // else we push in reverse order we predefine row size
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        bool is_left_to_right = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                int index = is_left_to_right? i: size-i-1;
                row[index] = node->val;

                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            is_left_to_right = !is_left_to_right;
            result.push_back(row);
        }
        return result;
    }
};