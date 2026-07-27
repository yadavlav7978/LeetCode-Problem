class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

       unordered_map<int,int>mp;

       int n=nums.size();
       long long sum=0;

       for(int i=0;i<n;i++){

            int key=target-nums[i];

            if(mp.find(key)!=mp.end()){
                return {mp[key],i};
            }

            mp[nums[i]]=i;
       }

       return {-1,-1};

        
    }
};