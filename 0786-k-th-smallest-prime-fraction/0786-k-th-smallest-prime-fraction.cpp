class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0, r = 1;
        int p = 0, q = 1;
        int n = arr.size();
        while(l < r){
            double m = l + (r - l )/ 2;
            int cnt = 0, p = 0;
            for(int i=0, j=n-1; i<n; i++){
                while(j >= 0 && arr[i] > m * arr[n-1-j]) j--;
                cnt += (j + 1);
                if(j>=0 && p * arr[n-1-j] < q * arr[i]) {
                    p = arr[i];
                    q = arr[n-1-j];
                }
            }
            if(cnt < k) l = m;
            else if(cnt > k) r = m;
            else return {p , q};
        }
        return {-1, -1};
    }
};

// a / b = m;
