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

    int path1=root->val+lsum;
    int path2=root->val+rsum;
    int path3=root->val+lsum+rsum;

    ans=max({ans,path1,path2,path3});

    return max({root->val,path1,path2,0});

}
    int maxPathSum(TreeNode* root) {

      maxSum(root);

      return ans;

        
    }
};