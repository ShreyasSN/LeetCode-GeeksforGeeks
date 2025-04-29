class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[128], m2[128];

        fill(m1, m1+128, -1);
        fill(m2, m2+128, -1);


        int n = s.size();

        for(int i=0; i<n; i++){
            if(m1[s[i]] != m2[t[i]])  return false;

            m1[s[i]] = m2[t[i]] = i;
        }
        return true;
    }
};