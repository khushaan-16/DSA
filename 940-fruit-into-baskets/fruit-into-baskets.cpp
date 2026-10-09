class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0, maxlen = 0;
        unordered_map<int, int> hash;

        while (r < n) {
            hash[fruits[r]]++;

            while (hash.size() > 2) {
                hash[fruits[l]]--;

                if (hash[fruits[l]] == 0) {
                    hash.erase(fruits[l]);
                }

                l++;
            }

            int len = r - l + 1;
            maxlen = max(len, maxlen);

            r++;
        }

        return maxlen;
    }
};