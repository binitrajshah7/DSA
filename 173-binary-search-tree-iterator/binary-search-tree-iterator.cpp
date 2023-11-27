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

// Time Complexity: O(H): height of binary tree other operations are O(1)
// Intuition: Whenever we reach a root we push all the left of root to our stack as we have to do inorder traversal
// when next is called we take the top element from stack and return but before that we push all the left node of root->right
// to our stack so that we can maintain our inorder traversal
class BSTIterator {
    stack<TreeNode*> st;
private:
    void push_all(TreeNode * root){
        while(root != NULL){
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        push_all(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        push_all(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */