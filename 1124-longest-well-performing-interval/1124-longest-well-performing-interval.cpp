class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size(), res = 0;
        
        unordered_map<int,int> seen;
        int score=0;
        for(int i=0; i<n; i++)
        {
            hours[i] > 8 ? ++score : --score;
            
            if(score>0)
            {
                res = i+1;
            }
            else{
                if(seen.find(score) == seen.end()) {
                    seen[score] = i;
                }
                if(seen.find(score-1) != seen.end()){
                    res = max(res, i - seen[score-1]);
                }
            }
        }
        
        return res;
        
    }
};