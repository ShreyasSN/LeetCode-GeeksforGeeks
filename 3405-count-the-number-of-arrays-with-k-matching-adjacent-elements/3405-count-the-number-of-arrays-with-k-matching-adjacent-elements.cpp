class Solution {
    int mod = 1e9 + 7;
    using ll = long long;
    ll exponent(ll base, ll exp){
        ll res = 1;
        while(exp > 0){
            if(exp & 1) (res *= base) %= mod;
            (base *= base) %= mod;
            exp >>= 1;
        }
        return res;
    }
    ll modInverse(ll x){
        return exponent(x, mod-2);
    }
    ll nCr(int n, int r, vector<ll>& fact){
        return fact[n] * modInverse(fact[r]) % mod * modInverse(fact[n-r]) % mod;
    }
public:
    int countGoodArrays(int n, int m, int k) {
        vector<ll> fact(n+1, 1);
        for(int i=2; i<=n; i++) fact[i] = fact[i-1] * i % mod;
        ll res = nCr(n-1, k, fact);
        (res *= m) % mod;
        (res *= exponent(m-1, n-k-1)) % mod;
        return res;
    }
};