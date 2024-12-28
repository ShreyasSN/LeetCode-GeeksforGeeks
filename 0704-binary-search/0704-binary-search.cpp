class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high, low=0;
        high = int(nums.size()) - 1;
        while(low <= high)
        {
            
            int mid = low + (high - low)/2;
            if(target == nums[mid])
                {return mid;}
            else if(target > nums[mid])
                {low = mid + 1;}
            else
                {high = mid - 1;}
            
        }
        return -1;
    }
};