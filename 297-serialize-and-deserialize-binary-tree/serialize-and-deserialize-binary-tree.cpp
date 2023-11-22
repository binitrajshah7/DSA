/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(!root)
            return s;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL)
                s.append("#,");
            else
                s.append(to_string(node->val) + ",");

            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        queue<TreeNode*> q;

        // helps to iterate through string as objects
        stringstream s(data);
        string str;

        // this line will iterate to string s as objects with comma separated value and assign the value to str
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* left_node = new TreeNode(stoi(str));
                node->left = left_node;
                q.push(left_node);
            }

            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* right_node = new TreeNode(stoi(str));
                node->right = right_node;
                q.push(right_node);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));