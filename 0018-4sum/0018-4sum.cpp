class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        ksum(nums, target, 4);
        return res;
    }

    void ksum(const vector<int>& a, int t, int k) {
        vector<int> temp;
        dfs(a, 0, (int)a.size() - 1, t, k, temp);
    }

    void dfs(const vector<int>& a, int l, int r, int t, int k, vector<int>& p) {
        if (k == 2) {
            while (l < r) {
                if (a[l] + a[r] == t) {
                    p.push_back(a[l]);
                    p.push_back(a[r]);
                    res.push_back(p);
                    p.pop_back();
                    p.pop_back();
                    while (l + 1 < r && a[l] == a[l + 1])
                        l++;
                    l++, r--;
                } else if (a[l] + a[r] > t)
                    r--;
                else
                    l++;
            }
        }
        while (l < r) {
            p.push_back(a[l]);
            dfs(a, l + 1, r, t - a[l], k - 1, p);
            p.pop_back();
            while (l + 1 < r && a[l] == a[l + 1])
                l++;
            l++;
        }
        return;
    }
};