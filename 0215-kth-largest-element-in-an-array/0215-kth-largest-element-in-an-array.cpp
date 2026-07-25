class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 3 2 1
        // k=2
        // 1 2 3

        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto it:nums){

            pq.push(it);

            if(pq.size()>k){
                pq.pop();
            }
        }

        return pq.top();
    }
};