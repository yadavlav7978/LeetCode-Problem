class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();

        vector<int>lis;

        for(int i=0;i<n;i++){

            int indx=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();

            if(indx<lis.size()){
                lis[indx]=nums[i];
            }else{
                lis.push_back(nums[i]);
            }
        }

        return lis.size();
        
    }
};