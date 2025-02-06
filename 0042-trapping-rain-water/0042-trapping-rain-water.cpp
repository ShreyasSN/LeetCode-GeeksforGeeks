class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0), right(n,0);
        left[0] = height[0]; 
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height.back();
        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1], height[i]);
        }
        int res = 0;
        for(int i=0; i<n; i++){
            res += min(right[i], left[i]) - height[i];
        }
        return res;
    }
};