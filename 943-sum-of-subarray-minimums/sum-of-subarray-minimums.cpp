class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        int mod = 1e9 + 7;

        vector<int> leftLen(n), rightLen(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            leftLen[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            rightLen[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        // Calculate contribution of every element
        for (int i = 0; i < n; i++) {
            long long contribution =
                (1LL * arr[i] * leftLen[i] % mod) * rightLen[i] % mod;

            sum = (sum + contribution) % mod;
        }

        return sum;
    }
};