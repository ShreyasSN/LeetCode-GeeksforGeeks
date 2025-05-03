const long mod = 1e9+9;
class Solution {
    long pow(long x, int y) {
        long res = 1;
        for(;y;y>>=1){
            if(y&1) res = (res*x) % mod;
            x = (x*x)%mod;
        }
        return res;
    }
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        long hash = 0, pMod = pow(53, minSize-1);
        int l=0, r=0, res = 0;
        unordered_map<long,int> count, occ;
        for(int i=0; i<s.size(); i++) {
            count[s[i]]++;
            if(i - l + 1 > minSize) {
                hash -= (s[l] - 'a') * pMod;
                if(--count[s[l]]==0) count.erase(s[l]);
                l++;
            }
            hash = (hash * 53 + s[i] - 'a') % mod;
            if(i - l + 1 == minSize && count.size() <= maxLetters) {
                res = max(res, ++occ[hash]);
            }
        }
        return res;
    }
};