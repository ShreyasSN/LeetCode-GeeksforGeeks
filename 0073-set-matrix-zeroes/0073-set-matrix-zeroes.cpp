class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        auto modify = [&](int x, int y) {
            for (int i=0; i<m; i++) {
                matrix[x][i] = 0;
            }
            for (int i=0; i<n; i++) {
                matrix[i][y] = 0;
            }
        };

        vector mark (n, vector<bool>(m, false));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    mark[i][j] = true;
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mark[i][j]) {
                    modify(i, j);
                } 
            }
        }
    }
};