const int N = 3e5 + 9;

int a[N];
struct ST {
    int t[2 * N]; 
    ST() { memset(t, 0, sizeof t); }

    int merge(int l, int r) { return l | r; }

    void build(int n, int b, int e) {
        if (b > e) return;
        if (b == e) {
            t[n] = a[b];
            return;
        }
        int mid = (b + e) >> 1, lft = n << 1, rgt = lft | 1;
        build(lft, b, mid);
        build(rgt, mid + 1, e);
        t[n] = merge(t[lft], t[rgt]);
    }
    
    int query(int n, int b, int e, int i, int j) {
        if (b > j || e < i) return 0;
        if (b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, lft = n << 1, rgt = lft | 1;
        int L = query(lft, b, mid, i, j);
        int R = query(rgt, mid + 1, e, i, j);
        return merge(L, R);
    }
} T;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) a[i] = nums[i];

        T.build(1, 0, n - 1);

        int ans = INT_MAX;
        for (int l = 0; l < n; ++l) {
            int lo = l, hi = n - 1, best = INT_MAX;
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                int cur = T.query(1, 0, n - 1, l, mid);
                ans = min(ans, abs(k - cur));
                if (cur == k) return 0;
                if (cur > k) hi = mid - 1;
                else lo = mid + 1;
            }
        }

        return ans;
    }
};
