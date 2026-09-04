class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate nums[i]
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Since array is sorted, no possible answer
            if (nums[i] > 0)
                break;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    // Store current values before moving
                    int leftVal = nums[left];
                    int rightVal = nums[right];

                    left++;
                    right--;

                    // Skip duplicates
                    while (left < right && nums[left] == leftVal)
                        left++;

                    while (left < right && nums[right] == rightVal)
                        right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};