class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        int mid = n>>1;
        for(int i=0; i<n; i++)
        {
            sum += mat[i][i];
            sum += mat[n-1-i][i];
        }
        if(n%2 == 1) sum -= mat[mid][mid];
        return sum;
    }
};