class Solution {
    public int maxSubArray(int[] nums) {

        int n=nums.length;
        int sum=0;
        int maxSum=Integer.MIN_VALUE;


        for(int val:nums){
            maxSum=Math.max(maxSum,val);

        }

        for(int i=0;i<n;i++){

            sum+=nums[i];

            if(sum<0){
                sum=0;
            }else{
               maxSum=Math.max(maxSum,sum);

            }
        }

        return maxSum;
        
    }
}