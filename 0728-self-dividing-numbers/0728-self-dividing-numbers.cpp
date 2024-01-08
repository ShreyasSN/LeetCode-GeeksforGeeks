class Solution {
    bool CheckSelfDividing(int n){
        int num = n;
        if(n%10 == 0) return false;
        
        while(n > 0){
            int digit = n%10;
            n /= 10;
            if(digit == 0 || num % digit != 0) return false;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left; i<=right; i++){
            if(CheckSelfDividing(i)) res.push_back(i);
        }
        return res;
    }
};