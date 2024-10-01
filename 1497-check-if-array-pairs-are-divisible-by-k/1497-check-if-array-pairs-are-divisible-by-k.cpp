class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>c(k, 0);
        for(int &x: arr){
            int rem = (x%k + k)%k;
            c[rem]+=1;
        }

        if(c[0]&1) return false;
        for(int i=1; i<k; i++){
            if(c[i] != c[k-i]) return false;
        }
        return true;
    }
};