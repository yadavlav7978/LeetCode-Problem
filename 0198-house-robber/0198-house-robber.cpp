class Solution {
public:

int n;

int amount(vector<int>& nums,int i,vector<int>&dp){

    if(i>=n) return 0;

    if(dp[i]!=-1) return dp[i];

    int skip=amount(nums,i+1,dp);
    int notskip=nums[i]+amount(nums,i+2,dp);

    return dp[i]=max(skip,notskip);
}

int rob(vector<int>& nums) {

    n=nums.size();
    vector<int>dp(n,-1);

    return  amount(nums,0,dp);


        
    }
};