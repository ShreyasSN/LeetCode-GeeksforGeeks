class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> head_pq, tail_pq;
        int head = 0, tail = costs.size()-1;
        long long ans = 0;
        while(k--)
        {
            while(head_pq.size()<candidates && head <= tail) head_pq.push(costs[head++]);
            while(tail_pq.size()<candidates && head <= tail) tail_pq.push(costs[tail--]);
            
            int a = head_pq.size() > 0 ? head_pq.top() : INT_MAX;
            int b = tail_pq.size() > 0 ? tail_pq.top() : INT_MAX;
            
            if(a <= b){
                ans += a;
                head_pq.pop();
            }
            else{
                ans += b;
                tail_pq.pop();
            }
         }
        return ans;
    }
};