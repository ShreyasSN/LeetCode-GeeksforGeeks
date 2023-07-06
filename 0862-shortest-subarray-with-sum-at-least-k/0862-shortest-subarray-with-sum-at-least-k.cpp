class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = n+1;
        
        deque<long long> d;
        
        vector<long long> p_sum(n);
        p_sum[0] = nums[0];
         
        for(int i=0; i<n; i++)
        {
            if(i>0){
                 p_sum[i] = nums[i] + p_sum[i-1];
            }
            
            if(p_sum[i] >= k){
                res = min(res, i+1);
            }
            
            while(d.size()>0 && p_sum[i] - p_sum[d.front()] >= k){
                res = min(res, i - static_cast<int>(d.front())), d.pop_front();
            }
            
            while(d.size() && p_sum[i] <= p_sum[d.back()]){
                d.pop_back();
            }
            
            d.push_back(i);
        }
        
        return res <= n ? res : -1;
    }
};