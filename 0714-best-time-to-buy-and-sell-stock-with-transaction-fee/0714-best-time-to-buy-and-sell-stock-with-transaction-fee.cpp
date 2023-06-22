class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int hold = -prices[0], free = 0;
        for(int i=1; i<n; i++)
        {
            int temp = hold;
            hold = max(hold, free - prices[i]);
            free = max(free, prices[i] + temp - fee);
            
        }
        return free;
    }
};