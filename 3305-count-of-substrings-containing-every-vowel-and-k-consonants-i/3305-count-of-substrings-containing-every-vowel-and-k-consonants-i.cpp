class Solution {
    bool check(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int res=0, lc=n, l=0, r=0,c=0;
        vector<int> nextC(n);
        unordered_map<char,int> vowel;
        for(int i=n-1; i>=0; i--){
            nextC[i] = lc;
            if(!check(word[i])) lc=i;
        }

        while(r<n){
            if(check(word[r])) vowel[word[r]]++;
            else c++;

            while(c>k && l <= r){
                if(check(word[l])){if(--vowel[word[l]] == 0)vowel.erase(word[l]);} 
                else c--;
                l++;
            }

            while(vowel.size() == 5 && c == k && l < r){
                res += nextC[r] - r;
                if(check(word[l])) {if(--vowel[word[l]]==0) vowel.erase(word[l]);}
                else c--;
                l++; 
            }
            r++;
        }
        return res;
    }
};