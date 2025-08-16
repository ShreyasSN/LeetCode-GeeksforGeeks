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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;
        int idx = bsearch(l, r, [&](int x) {
            return matrix[x/m][x%m] >= target;
        });
        return matrix[idx/m][idx%m] == target;
    }
};