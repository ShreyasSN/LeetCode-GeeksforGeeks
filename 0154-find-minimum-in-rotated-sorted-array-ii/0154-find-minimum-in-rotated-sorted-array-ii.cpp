class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<r){
            int m=(l+r)/2;
            if(nums[l]>nums[m]) r=m;
            else if(nums[r]<nums[m]) l=m+1;
            else r--;
        }
        return nums[l];
    }
};