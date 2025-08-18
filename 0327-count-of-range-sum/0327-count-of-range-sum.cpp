class Solution {
    int dnc(vector<long>& pref,int lower,int upper, int l, int r) {
        if(r-l<=1) return 0;
        int mid = (l+r)>>1;
        int n=mid,m=mid,cnt=0;
        cnt=dnc(pref,lower,upper,l,mid)+dnc(pref,lower,upper,mid,r);
        for(int i=l;i<mid;i++){
            while(m<r&&pref[m]-pref[i]<lower)m++;
            while(n<r&&pref[n]-pref[i]<=upper)n++;
            cnt+=(n-m);
        }
        inplace_merge(pref.begin()+l,pref.begin()+mid,pref.begin()+r);
        return cnt;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<long>pref(n+1,0);
        for(int i=0;i<n;i++)pref[i+1]=pref[i]+nums[i];
        return dnc(pref,lower,upper,0,n+1);
    }
};