class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> a1(26, 0), a2(26, 0), ans;
        for(auto& x : p) a1[x - 'a']++;
        auto issame = [&]{
            for(int i=0; i<26; i++) if(a1[i] != a2[i]) return 0;
            return 1;
        };
        for(int i=0; i<s.size(); i++){
            a2[s[i] - 'a']++;
            if(i >= p.size()) a2[s[i-p.size()] - 'a']--;
            if(issame()) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }

};


