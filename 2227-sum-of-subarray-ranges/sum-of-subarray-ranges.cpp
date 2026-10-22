class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sumMax = 0, sumMin = 0;
        stack<int> st;

        // Sum of subarray minimums
        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&
                   (i == n || nums[st.top()] >= nums[i])) {
                int index = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                sumMin += 1LL * nums[index] *
                          (index - left) * (right - index);
            }

            if (i < n) st.push(i);
        }

        while (!st.empty()) st.pop();

        // Sum of subarray maximums
        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&
                   (i == n || nums[st.top()] <= nums[i])) {
                int index = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                sumMax += 1LL * nums[index] *
                          (index - left) * (right - index);
            }

            if (i < n) st.push(i);
        }

        return sumMax - sumMin;

    }
};