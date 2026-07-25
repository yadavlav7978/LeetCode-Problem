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
int ans=INT_MIN;

int maxSum(TreeNode* root){

    if(!root) return 0;

    int lsum=maxSum(root->left);
    int rsum=maxSum(root->right);

    ans=max(ans,max(0,lsum)+max(0,rsum)+root->val);

    return root->val+max({0,lsum,rsum});

}
    int maxPathSum(TreeNode* root) {

      maxSum(root);

      return ans;

        
    }
};