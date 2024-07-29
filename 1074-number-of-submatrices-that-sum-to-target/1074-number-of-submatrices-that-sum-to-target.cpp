class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int target) {
        int m = a.size(), n = a[0].size();
        int res = 0;

        for(int i=0; i<m; i++){
            for(int j=1; j<m; j++){
                a[i][j] += a[i][j-1];
            }
        }

        unordered_map<int, int> seen;
        for(int i=0; i<m; i++){
            for(int j=i; j<n; j++){
                seen = {{0, 1}};
                int cur = 0;
                for(int k=0; k<m; k++){
                    cur += a[k][j] - (i>0 ? a[k][i-1]: 0);
                    res += seen.find(cur - target) != seen.end() ? seen[cur - target] : 0;
                    seen[cur]++;
                }
            }
        }
        return res;
    }
};