#define inf 0x3f3f3f3f
class Solution {
    static const int N = 1 << 17;
    int n;

    struct vertice {
        int64_t pref, suf, sum, maxSeg;

        vertice() : pref(-inf), suf(-inf), sum(-inf), maxSeg(-inf) {}
        vertice(int64_t v) : pref(v), suf(v), sum(v), maxSeg(v) {}

        static vertice combine(const vertice &l, const vertice &r) {
            vertice res;
            res.pref = max(l.pref, l.sum + r.pref);
            res.suf = max(r.suf, r.sum + l.suf);
            res.sum = l.sum + r.sum;
            res.maxSeg = max({l.maxSeg, r.maxSeg, l.suf + r.pref});
            return res;
        }
    };

    vertice t[2 * N];

    void build() {
        for (int i = n - 1; i > 0; --i) {
            t[i] = vertice::combine(t[i * 2], t[i * 2 + 1]);
        }
    }

    vertice query(int l, int r) {
        vertice resl(-inf), resr(-inf);
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = vertice::combine(resl, t[l++]);
            if (r & 1) resr = vertice::combine(t[--r], resr);
        }
        return vertice::combine(resl, resr);
    }

public:
    int maxSubArray(vector<int>& nums) {
        n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            t[n + i] = vertice(nums[i]);
        }
        build();  
        return query(0, n).maxSeg; 
    }
};
