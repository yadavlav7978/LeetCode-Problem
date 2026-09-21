class Solution {
public:

vector<int>ans;
int dp[1002][1003];
int n;

void call(vector<int>&nums,int i,int prev,vector<int>&temp){

  if(i>=n){
    if(temp.size()>ans.size()){
        ans=temp;
    }
    return ;
  }

  if((int)temp.size()>dp[i][prev+1] and (prev==-1 || nums[i]%nums[prev]==0)){
    dp[i][prev+1]=temp.size();
      temp.push_back(nums[i]);
      call(nums,i+1,i,temp);
      temp.pop_back();
  }

  call(nums,i+1,prev,temp);

}

vector<int>largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        
         n=nums.size();

        vector<int>temp;
        memset(dp,-1,sizeof(dp));

        call(nums,0,-1,temp);

        return ans;
    }
};