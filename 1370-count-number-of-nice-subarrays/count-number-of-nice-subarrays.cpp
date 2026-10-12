class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int l = 0, sum = 0, cnt = 0;
        int n = nums.size();

        for (int r = 0; r < n; r++) {
            sum += nums[r] % 2;

            while (sum > k) {
                sum -= nums[l] % 2;
                l++;
            }

            cnt += r - l + 1;
        }

        return cnt;
    }
};
