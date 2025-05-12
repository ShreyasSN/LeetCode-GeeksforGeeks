class Solution {
    static const int N = 1e5;  
    int n; 
    int t[2 * N];

    void build() {  
        for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
    }

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += t[l++];
            if (r&1) res += t[--r];
        }
        return res;
    }
public:
    int minimumDifference(vector<int>& nums, int k) {
        n = nums.size();
        for (int i = 0; i < n; i++) t[i + n] = nums[i];
        build();

        int ans = INT_MAX;
        for (int l = 0; l < n; ++l) {
            int lo = l, hi = n - 1, best = INT_MAX;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                int cur = query(l, mid+1);
                ans = min(ans, abs(k - cur));
                if (cur == k) return 0;
                if (cur > k) hi = mid - 1;
                else lo = mid + 1;
            }
        }
        return ans;
    }
};
