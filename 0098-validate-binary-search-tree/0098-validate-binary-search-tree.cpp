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

   bool isValid(TreeNode* root,long low,long high){

    if(!root) return true;

    int cur=root->val;

    if(cur<=low || high<=cur) return false;

    bool l=isValid(root->left,low,cur);
    bool r=isValid(root->right,cur,high);

    return l&&r;


   }

    bool isValidBST(TreeNode* root) {

        return isValid(root,LONG_MIN,LONG_MAX);
    }
};