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
    int diameter(TreeNode* root,int& ans){

        if(!root) return 0;

        int ldia=diameter(root->left,ans);
        int rdia=diameter(root->right,ans);

        int cur=ldia+rdia+1;

        ans=max(ans,cur);

        return max(ldia,rdia)+1;

    }

    int diameterOfBinaryTree(TreeNode* root) {

        int ans=0;

        diameter(root,ans);

        return ans-1;
        
    }
};