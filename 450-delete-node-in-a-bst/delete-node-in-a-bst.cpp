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
    // Intuition: Until we find the target node we  traverse to that node either in left or right subtree
    // If we reach at a node which is our root then we can have 3 conditions either it has left null, right null or both not null
    // if left null we return right subtree deleting the target node and returned will be attached to right parent node

    // if both not null then we find successor node i.e just greater node than target node and make root node to successor value
    // then delete successor as successor is left most element of right subtree it will definetely have left as null
    TreeNode* successor(TreeNode* root){
        root = root->right;
        while(root && root->left)
            root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);

        else{
            if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{
                TreeNode* successor_node = successor(root);
                root->val = successor_node->val;
                root->right = deleteNode(root->right, successor_node->val);
            }
        }   
        return root;
    }
};