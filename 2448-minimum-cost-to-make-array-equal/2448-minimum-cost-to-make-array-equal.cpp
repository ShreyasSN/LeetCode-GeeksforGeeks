class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
         int n = nums.size();
        vector<vector<int>> numsandcost(n, vector<int>(2));
        for(int i=0; i<n; i++)
        {
            numsandcost[i][0] = nums[i];
            numsandcost[i][1] = cost[i];
        }
        sort(numsandcost.begin(), numsandcost.end());
        
        vector<long long> prefixcost(n);
        prefixcost[0] = numsandcost[0][1];
        for(int i=1; i<n; i++)
            prefixcost[i] = numsandcost[i][1] + prefixcost[i-1];
        
        long long totalcost = 0ll;
        for(int i=1; i<n; i++)
            totalcost += 1ll * numsandcost[i][1] * (numsandcost[i][0] - numsandcost[0][0]);
        long long answer = totalcost;
        
        for(int i=1; i<n; i++)
        {
            int gap = numsandcost[i][0] - numsandcost[i-1][0];
            totalcost += 1ll * prefixcost[i-1] * gap;
            totalcost -= 1ll * (prefixcost[n-1] - prefixcost[i-1]) * gap;
            answer = min(answer, totalcost);
        }
        return answer;
    }
};  
