class Solution {
    template <typename T, typename U>
    T bsearch(T l, T r, U condition, bool Lbound = true, bool firstTSeq = false) {
        while (l < r) {
            T mid = l + (r - l + firstTSeq) / 2;
            if (condition(mid)) firstTSeq ? l = mid : r = mid;
            else firstTSeq ? r = mid - 1 : l = mid + 1;
        }
        return (Lbound ? l : l - 1);
    }
public:
    int mySqrt(int x) {
        int t = bsearch(0, x, [&](int m) {
            return 1ll * m * m >= x;
        });
        return 1ll * t * t == x ? t : t - 1;
    }
};