class Solution {
    const long mod = 1e9+9;
    const int base = 53;

    vector<long> computePrefixHashes(const string& s, vector<long>& power) {
        int n = s.size();
        vector<long> prefix(n + 1, 0);
        power[0] = 1;
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = (prefix[i] * base + (s[i] - 'a')) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }
        return prefix;
    }

    long getHash(int l, int r, const vector<long>& prefix, const vector<long>& power) {
        long hashVal = (prefix[r + 1] - (prefix[l] * power[r - l + 1]) % mod + mod) % mod;
        return hashVal;
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.empty()) return {};
        int wordLen = words[0].size(), numWords = words.size();
        int windowLen = wordLen * numWords;
        if (s.size() < windowLen) return {};

        unordered_map<long, int> wordHashCount;
        for (const string& word : words) {
            long h = 0;
            for (char c : word) {
                h = (h * base + (c - 'a')) % mod;
            }
            wordHashCount[h]++;
        }

        vector<long> power(s.size() + 1), prefix = computePrefixHashes(s, power);
        vector<int> res;

        for (int offset = 0; offset < wordLen; ++offset) {
            int left = offset, count = 0;
            unordered_map<long, int> seen;

            for (int right = offset; right + wordLen <= s.size(); right += wordLen) {
                long h = getHash(right, right + wordLen - 1, prefix, power);

                if (wordHashCount.count(h)) {
                    seen[h]++;
                    count++;

                    while (seen[h] > wordHashCount[h]) {
                        long removeHash = getHash(left, left + wordLen - 1, prefix, power);
                        seen[removeHash]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == numWords) {
                        res.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return res;
    }
};
