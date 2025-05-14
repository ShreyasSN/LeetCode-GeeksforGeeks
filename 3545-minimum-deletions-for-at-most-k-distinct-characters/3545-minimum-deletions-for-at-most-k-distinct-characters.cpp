class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> cnt(26, 0);
        int unique = 0;
        int n = s.size();
        for(char& c:s) {
            if(cnt[c -'a']++ == 0) unique++;
        }
        int res = 0;
        sort(cnt.begin(), cnt.end());
        int i = 0;
        while(unique > k && i < 26) {
            if(cnt[i] == 0) {
                i++;
                continue;
            }
            res += cnt[i++];
            unique--;
        }
        return res;
    }
};