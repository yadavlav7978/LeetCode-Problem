class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int>v;
        v=nums;
        
        sort(v.begin(),v.end());
        
        
        int f=-1;
        int i;
        
        for(i=0; i<nums.size(); i++){
            
            if(nums[i]!=v[i]){
               f=i; 
                break;
            }
        }
        
        int s=-1;
        
           for(int j=nums.size()-1; j>i; j--){
            
            if(nums[j]!=v[j]){
                s=j; 
                break;
            }
        }
        
        if(f!=-1 && s!=-1){
            
            return s-f+1;
        }
       
        return 0;
        
    }
};