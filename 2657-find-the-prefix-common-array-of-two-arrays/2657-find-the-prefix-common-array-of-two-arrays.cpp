class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> a,b;
        vector<int> res(n, 0);
        res[0] = A[0] == B[0];
        if(n == 1){
            return res;
        }
        a[A[0]]++;
        b[B[0]]++;
        for(int i=1; i<n; i++){
            a[A[i]]++;
            b[B[i]]++;
            if(A[i] == B[i]) res[i] = res[i-1] + 1;
            else if(a[B[i]] || b[A[i]]) res[i] = res[i-1] + a[B[i]] + b[A[i]];
            else res[i] = res[i-1];
        }
        return res;
    }
};