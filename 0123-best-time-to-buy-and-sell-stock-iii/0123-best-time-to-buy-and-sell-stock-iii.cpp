class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int free1 = 0, free2 = 0;
        for(int x: prices){
            free2 = max(free2, hold2+x);
            hold2 = max(hold2, free1-x);
            free1 = max(free1, hold1+x);
            hold1 = max(hold1, -x);
        }
        return free2;
    }
};