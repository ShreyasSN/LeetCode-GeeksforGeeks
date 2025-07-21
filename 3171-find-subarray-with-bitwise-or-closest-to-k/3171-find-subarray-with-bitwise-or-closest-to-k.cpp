struct SegTree {
    vector<int> t;
    int n;

    SegTree(vector<int>& a) {
        n = a.size();
        t.resize(2 * n);
        build(a);
    }

    int merge(int l, int r) { return l | r; }

    void build(vector<int>& a) { 
        for (int i=0; i<n; i++) t[i+n] = a[i];
        for (int i = n - 1; i > 0; --i) t[i] = merge(t[i<<1], t[i<<1|1]);
    }

    int query(int l, int r) { 
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)  {
            if (l & 1) res = merge(res, t[l++]);
            if (r & 1) res = merge(res, t[--r]);
        }
        return res;
    }
};

class Solution {
public:
    int minimumDifference(vector<int>& a, int k) {
        int n = a.size();
        SegTree seg(a);  

        int res = INT_MAX;
        for (int start = 0; start < n; ++start) {
            int lo = start, hi = n - 1;

            while (lo <= hi) {
                int mid = (lo + hi) >> 1;

                int val = seg.query(start, mid);
                res = min(res, abs(k - val));

                if (val == k) return 0;
                if (val > k) hi = mid - 1;
                else lo = mid + 1;
            }
        }

        return res;
    }
};
