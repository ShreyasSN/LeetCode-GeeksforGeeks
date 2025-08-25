class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        long total=accumulate(arr.begin(), arr.end(), 0ll) * 1LL * 2;
        int cur=0,mx=0;
        for(int i=0; i<2*n; i++){
            int j=i%n;
            cur=max(arr[j],cur+arr[j]);
            mx=max(cur,mx);
        }
        if(mx==total){
            return total * k / 2;
        } else{
            return mx;
        }
    }
};