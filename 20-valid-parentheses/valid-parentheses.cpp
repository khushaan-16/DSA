class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);  // Fix 1: push s[i], not st[i]
            }
            else {
                if(st.empty()) return false;

                char ch = st.top();
                st.pop();

                if ((s[i] == ')' && ch != '(') ||
                    (s[i] == '}' && ch != '{') ||
                    (s[i] == ']' && ch != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};