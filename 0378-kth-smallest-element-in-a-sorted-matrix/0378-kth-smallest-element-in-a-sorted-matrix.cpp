class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int l = matrix[0][0], r = matrix[m-1][n-1];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                int j = n - 1;
                while (j >= 0 && matrix[i][j] > mid) --j;
                cnt += (j + 1);
            }
            if (cnt < k) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};
