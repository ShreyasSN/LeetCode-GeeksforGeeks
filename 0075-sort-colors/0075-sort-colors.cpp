class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size()-1, zero=0, second=n;
        for(int i=0; i<=second; i++)
        {
            while(nums[i]==2 && second>i) swap(nums[i], nums[second--]);
            while(nums[i]==0 && zero<i) swap(nums[i], nums[zero++]);
        }
    }
};