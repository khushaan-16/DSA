class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        int minlen = 1e9, sIndex = -1, cnt = 0;

        int hash[256] = {0};
        int n = s.size();
        int m = t.size();

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < n) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;

            while (cnt == m) {
                int len = r - l + 1;

                if (len < minlen) {
                    minlen = len;
                    sIndex = l;
                }

                hash[s[l]]++;

                if (hash[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};