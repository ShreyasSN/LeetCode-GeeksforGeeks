class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> res;
        for(const auto& cur: intervals) {
            if (end < cur[0]) {
                res.push_back({start, end});
                start = cur[0], end = cur[1];
            } else if(end > cur[1]) {
                end = cur[1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};