class Solution {
    bool checkPrime(int x) {
        if(x <= 1) return false;
        if(x <= 3) return true;
        if(x % 2 == 0 || x % 3 == 0) return false;

        for(int i=5; i<= sqrt(x); i += 6) {
            if(x % i == 0 || x % (i + 2) == 0) return false;
        } 

        return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int& i:nums) mp[i]++;

        for(auto& [i, freq]: mp) {
            if(checkPrime(freq)) {
                return true;
            }
        }

        return false;
    }
};