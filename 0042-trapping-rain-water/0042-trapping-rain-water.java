class Solution {
    public int trap(int[] height) {

        int n=height.length;

        int left=0;
        int right=n-1;

        int leftMax=0;
        int rightMax=0;

        int ans=0;

        while(left<right){

            leftMax=Math.max(leftMax,height[left]);
            rightMax=Math.max(rightMax,height[right]);

            int mn=Math.min(leftMax,rightMax);
            //7 5  10

            if(height[left]<height[right]){

                ans+=mn-height[left];
                left++;
            }else{
                ans+=mn-height[right];
                right--;
            }

        }

        return ans;
        
    }
}