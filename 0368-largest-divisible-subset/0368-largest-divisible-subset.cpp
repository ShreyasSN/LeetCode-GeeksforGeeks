class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev(n), dp(n);
        sort(nums.begin(), nums.end());
        int mx=0;
        int idx=-1;
        for(int i=0;i<n;i++){
            dp[i]=1;
            prev[i]=-1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0&&dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>mx){
                mx=dp[i];
                idx=i;
            }
        }
        vector<int> res;
        while(idx!=-1){
            res.push_back(nums[idx]);
            idx=prev[idx];
        }
        return res;
    }
};