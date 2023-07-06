class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int n=nums.size(), res=n+1;
        
        deque<int> d;
        
        for(int i=0; i<n; i++)
        {
            if(i > 0)
            {
                nums[i] += nums[i-1];
                
            }
            
            if(nums[i] >= k) res = min(res, i+1);
            
            while(d.size() > 0 && nums[i] - nums[d.front()] >= k)
                res = min(res, i - d.front()), d.pop_front();
            
            while(d.size() > 0 && nums[i] <= nums[d.back()])
                d.pop_back();
            
            d.push_back(i);
            
        }
        
        return res <= n ? res : 0;
    }
};