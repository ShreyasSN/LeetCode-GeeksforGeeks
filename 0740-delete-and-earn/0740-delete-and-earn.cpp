class Solution {
    int f(vector<int>& a, int i, vector<int>& dp) {
        if (i == a.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int cur = a[i];
        int sum = a[i];
        int j = i + 1;
        while (j < a.size() && a[j] == cur) {
            sum += a[j++];
        }
        while (j < a.size() && a[j] == cur + 1)
            j++;
        return dp[i] = max(sum + f(a, j, dp), f(a, i + 1, dp));
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(10001, 0);
        for(int &i:nums) a[i] += i;
        int prev = 0, cur = 0;
        for(int val: a){
            int t = prev;
            prev = cur;
            cur = max(t + val, cur);
        } 
        return cur;
    }
};