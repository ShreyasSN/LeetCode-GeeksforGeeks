class FindSumPairs {
    vector<int> a, b;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : a(nums2), b(nums1) {
        cout << nums1.size() << ' ' << nums2.size();
    }
    
    void add(int index, int val) {
        a[index] += val;
    }

    int count(int tot) {
        int cnt = 0;
        map<int, int> mp;
        for(int i=0; i < b.size(); i++) {
            mp[b[i]]++;
        }
        
        for(int j = 0; j < a.size(); j++) {
            if(mp.contains(tot - a[j])) {
                cnt += mp[tot - a[j]];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */