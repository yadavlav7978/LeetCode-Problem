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
    int indx=0;
    string serialize(TreeNode* root) {

        if(!root) return "n";

        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data[indx]=='n'){
            indx+=2;
            return NULL;
        }

        string num="";

        while(data[indx]!=','){
            num+=data[indx];
            indx++;
        }

        int value=stoi(num);

        indx++;

        TreeNode* root=new TreeNode(value);

        root->left=deserialize(data);

        root->right=deserialize(data);

        return root;

        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));