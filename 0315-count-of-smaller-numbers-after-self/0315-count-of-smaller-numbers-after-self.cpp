namespace SegmentTree {
  template <class S, auto op, auto e>
  struct init {
public:
  init() : init(0) {}
  explicit init(int n, S init_val = e()) : init(std::vector<S>(n, init_val)) {}
  explicit init(const std::vector<S> &v) : _n(int(v.size())) {
    size = 1 << (32 - __builtin_clz(_n - 1));
    log = __builtin_ctz(size);
    d = std::vector<S>(2 * size, e());
    for (int i = 0; i < _n; i++) { d[size + i] = v[i]; }
    for (int i = size - 1; i >= 1; i--) { set(i); }
  }

  void update(int p, S x) {
    d[p += size] = x;
    for (int i = 1; i <= log; i++) set(p >> i);
  }
  S get(int p) const {
    return d[p + size];
  }
  S get_all() const { return d[1]; }
  S query(int l, int r) const {
    S sml = e(), smr = e();
    for (l += size, r += size + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
    }
    return op(sml, smr);
  }
private:
    int _n, size, log;
    std::vector<S> d;
    void set(int k) { d[k] = op(d[k << 1], d[k << 1 | 1]); }
  };
}
using ll = long long;
struct info {
  ll v;
  info() : v(0) {}
  info(ll _v) {
    v = _v;
  }
};
info e() { return info(0); }
info op(const info &l, const info &r) {
  return {l.v + r.v};
}
using segtree = SegmentTree::init<info, op, e>;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        map<int, int> mp;
        for (int x : nums) mp[x]; 
        int idx = 0;
        for (auto &kv : mp) kv.second = idx++; 
        int n = mp.size(); 
        if(n == 1) {
            return vector<int>(nums.size(), 0);
        }
        segtree st(n);
        vector<int> res(nums.size());

        for (int i = nums.size() - 1; i >= 0; --i) {
            int pos = mp[nums[i]];
            res[i] = (pos > 0 ? st.query(0, pos - 1).v : 0);
            st.update(pos, st.get(pos).v + 1);
        }
        return res;
    }
};
