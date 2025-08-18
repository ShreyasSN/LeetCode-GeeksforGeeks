int n;
struct node {
    int val;
    node() : val(0) {}
    node(int v) : val(v) {}
};
node t[2 * (1<<17)]{}; 
node merge(node l, node r) {
    return node(l.val + r.val);
}
void build() {
    for (int i = n - 1; i > 0; --i)
        t[i] = merge(t[i<<1], t[i<<1|1]);
}
void update(int p, int value) {
    for (t[p += n] = node(value); p > 1; p >>= 1)
        t[p>>1] = merge(t[p], t[p^1]);
}
node query(int l, int r) {
    node resl(0), resr(0);
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) resl = merge(resl, t[l++]);
        if (r&1) resr = merge(t[--r], resr);
    }
    return merge(resl, resr);
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();

        map<int, int> mp;
        int idx = 0;
        for (int x : nums) mp[x];
        for (auto &kv : mp) kv.second = idx++; 

        vector<int> res(n);
        for (int i = n - 1; i >= 0; --i) {
            int pos = mp[nums[i]];
            res[i] = query(0, pos).val;
            update(pos, 1);
        }
        return res;
    }
};
