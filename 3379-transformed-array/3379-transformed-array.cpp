class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            int steps = 0;
            int j = i;
            if(nums[i] > 0){
                steps = nums[i];
                while(steps--){
                    j = (j + 1) % n;
                }
                res[i] = nums[j];
            } else if(nums[i] < 0){
                steps = abs(nums[i]);
                while(steps--){
                    j = (j + n - 1) % n;
                }
                res[i] = nums[j];
            } else{
                res[i] = nums[j];
            }
        }
        return res;
    }
};