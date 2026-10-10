class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxf = 0, maxlen = 0;
        int n = s.size();
        int hash[26] = {0};

        while (r < n) {
            hash[s[r] - 'A']++;

            maxf = max(maxf, hash[s[r] - 'A']);

            int len = r - l + 1;

            while (len - maxf > k) {
                hash[s[l] - 'A']--;
                l++;

                len = r - l + 1;
            }

            maxlen = max(maxlen, len);
            r++;
        }

        return maxlen;
    }
};