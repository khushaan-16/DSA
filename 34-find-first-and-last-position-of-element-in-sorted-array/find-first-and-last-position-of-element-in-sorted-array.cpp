class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = n;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

    int upperBound(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = n;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > target) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int lb = lowerBound(nums, target);

        if (lb == n || nums[lb] != target)
            return {-1, -1};

        int ub = upperBound(nums, target);

        return {lb, ub - 1};
    }
};