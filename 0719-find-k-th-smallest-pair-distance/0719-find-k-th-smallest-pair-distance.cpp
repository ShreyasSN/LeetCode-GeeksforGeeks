class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> diff;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                diff.push_back(abs(nums[i] - nums[j]));
            }
        }
        sort(diff.begin(), diff.end());
        return diff[k-1];
    }
};