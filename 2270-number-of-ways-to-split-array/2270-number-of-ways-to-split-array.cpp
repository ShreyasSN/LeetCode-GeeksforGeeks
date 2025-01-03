class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref = {0};
        for(int &i: nums) pref.push_back(pref.back()+i);
        for(auto &i: pref) cout << i << " ";
        cout << '\n';
        int res = 0;
        for(int i=1;i<n;i++){
            if(pref[i] >= pref.back() - pref[i]) res ++;
        }
        return res;
    }
};

// 0, 2, 5, 6, 6

// i = 4
// 5
// 6