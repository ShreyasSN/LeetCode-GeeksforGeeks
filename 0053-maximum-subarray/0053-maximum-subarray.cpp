class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int cur=INT_MIN,mx=INT_MIN;
        for(int& i:nums){
            cur=max(cur+i,i);
            mx=max(cur,mx);
        }
        return mx;
    }
};