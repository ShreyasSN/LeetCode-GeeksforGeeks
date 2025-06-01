template <class Info, class Tag>
struct lazy_segtree {
#define ls(i) (i << 1)
#define rs(i) (i << 1 | 1)

  int n, s = 0;
  std::vector<Info> info;
  std::vector<Tag> tag;

  lazy_segtree(int _n = 0, Info t = Info()) { init(std::vector<Info>(_n, t)); }
  lazy_segtree(const std::vector<Info> &v) { init(v); }

  void init(const std::vector<Info> &v) {
    n = v.size();
    info.assign(n << 2, Info());
    tag.assign(n << 2, Tag());
    std::function<void(int, int, int)> build = [&](int i, int l, int r) {
      if (l == r) {
        info[i] = v[l];
        return;
      }
      int mid = (l + r) >> 1;
      build(ls(i), l, mid);
      build(rs(i), mid + 1, r);
      pushup(i);
    };
    build(1, s, n - 1);
  }

  void pushup(int i) { info[i] = info[ls(i)] + info[rs(i)]; }

  void pushdown(int i, int l, int r) {
    if (tag[i].val) {
      int mid = (l + r) >> 1;
      apply(ls(i), l, mid, tag[i]);
      apply(rs(i), mid + 1, r, tag[i]);
      tag[i] = Tag();
    }
  }

  void apply(int i, int l, int r, const Tag &t) {
    info[i].apply(l, r, t);
    tag[i].apply(t);
  }

  void modify(int i, int l, int r, int x, int y, const Tag &t) {
    if (x <= l && r <= y) {
      apply(i, l, r, t);
      return;
    }
    int mid = (l + r) >> 1;
    pushdown(i, l, r);
    if (x <= mid) modify(ls(i), l, mid, x, y, t);
    if (y > mid) modify(rs(i), mid + 1, r, x, y, t);
    pushup(i);
  }

  Info query(int i, int l, int r, int x, int y) {
    if (x <= l && r <= y) return info[i];
    int mid = (l + r) >> 1;
    pushdown(i, l, r);
    Info res;
    if (x <= mid) res = res + query(ls(i), l, mid, x, y);
    if (y > mid) res = res + query(rs(i), mid + 1, r, x, y);
    return res;
  }

  void modify(int l, int r, const Tag &t) { modify(1, s, n - 1, l, r, t); }
  Info query(int l, int r) { return query(1, s, n - 1, l, r); }

#undef ls
#undef rs
};

struct Tag {
  int val;
  Tag(int _val = 0) : val(_val) {}
  void apply(const Tag &t) { val += t.val; }
};

struct Info {
  int val;
  Info(int _val = 0) : val(_val) {}
  void apply(int l, int r, const Tag &t) { val += t.val; }
  Info operator+(const Info &o) const { return Info(std::max(val, o.val)); }
};

template <typename T>
class Sieve {
  static const int MAX_N = 100000;
public:
  vector<bool> isP;
  Sieve() : isP(MAX_N + 1, false) {}
  vector<bool> AtkinSieve(T n) {
    if (n > MAX_N) n = MAX_N;
    fill(isP.begin(), isP.end(), false);
    if (n >= 2) isP[2] = true;
    if (n >= 3) isP[3] = true;
    for (T x = 1; x * x <= n; x++) {
      for (T y = 1; y * y <= n; y++) {
        T N = (4 * x * x + y * y);
        if (N <= n && (N % 12 == 1 || N % 12 == 5)) isP[N] = !isP[N];
        N = (3 * x * x + y * y);
        if (N <= n && N % 12 == 7) isP[N] = !isP[N];
        N = (3 * x * x - y * y);
        if (x > y && N <= n && N % 12 == 11) isP[N] = !isP[N];
      }
    }
    for (T r = 5; r * r <= n; r++) {
      if (isP[r]) {
        for (T i = r * r; i <= n; i += r * r)
          isP[i] = false;
      }
    }
    return isP;
  }
};

class Solution {
public:
  vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    map<int, set<int>> occ;
    Sieve<int> sieve;
    auto is_prime = sieve.AtkinSieve(100000);
    vector<Info> init_vals(n, Info(0));
    lazy_segtree<Info, Tag> segtree(init_vals);

    auto upd = [&](int l, int r, int delta) {
      if (l <= r) segtree.modify(l, r, Tag(delta));
    };

    auto getmax = [&]() {
      return segtree.query(0, n - 1).val;
    };

    auto remove = [&](int val, int idx) {
      auto& indices = occ[val];
      int sz = indices.size();
      if (sz == 1) {
        upd(0, n - 1, -1);
      } else if (idx == *indices.begin()) {
        auto it = indices.begin(); ++it;
        upd(idx + 1, *it, -1);
      } else if (idx == *indices.rbegin()) {
        auto it = indices.end(); --it; --it;
        upd(*it + 1, idx, -1);
      }
      indices.erase(idx);
    };

    auto insert = [&](int val, int idx) {
      auto& indices = occ[val];
      int sz = indices.size();
      if (sz == 0) {
        upd(0, n - 1, 1);
      } else if (idx < *indices.begin()) {
        upd(idx + 1, *indices.begin(), 1);
      } else if (idx > *indices.rbegin()) {
        upd(*indices.rbegin() + 1, idx, 1);
      }
      indices.insert(idx);
    };

    for (int i = 0; i < n; i++) {
      if (is_prime[nums[i]]) {
        insert(nums[i], i);
      }
    }

    vector<int> res(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      int idx = queries[i][0], newVal = queries[i][1];
      if (nums[idx] != newVal) {
        if (is_prime[nums[idx]]) remove(nums[idx], idx);
        nums[idx] = newVal;
        if (is_prime[nums[idx]]) insert(nums[idx], idx);
      }
      res[i] = getmax();
    }

    return res;
  }
};