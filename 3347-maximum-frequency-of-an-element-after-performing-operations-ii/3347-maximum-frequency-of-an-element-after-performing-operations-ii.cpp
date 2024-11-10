class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        using ll = long long;
        map<ll,ll>mp;
        unordered_map<ll,ll>hash;
        set<ll>points;
        for(auto &it:nums){
            hash[it]++;
            mp[it-k]++;
            mp[it+k+1]--;
            points.insert(it);
            points.insert(it-k);
            points.insert(it+k+1);
        }
        ll ans=1;
        ll sum=0;
        for(auto &it:points){
            sum+=mp[it];
            ans=max(ans,hash[it]+min(sum-hash[it], static_cast<ll>(numOperations)));
            cout<< it << " " << hash[it]+min(sum-hash[it], static_cast<ll>(numOperations)) << endl;
        }
        return static_cast<int>(ans);
    }
};