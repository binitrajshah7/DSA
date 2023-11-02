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
    vector<int> get_average_nodes(TreeNode* root, int &count){
        if(!root)
            return vector<int> {0, 0};

        vector<int> left_sum = get_average_nodes(root->left, count);
        vector<int> right_sum = get_average_nodes(root->right, count);

        int num_of_nodes = 1 + left_sum[1] + right_sum[1];
        int total_node_sum = root->val + left_sum[0] + right_sum[0];

        if(round(total_node_sum/num_of_nodes) == root->val)
            count++;

        return vector<int> {total_node_sum, num_of_nodes};

    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        vector<int> result = get_average_nodes(root, count);
        return count;
    }
};