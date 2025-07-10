/*

32_Longest_Valid_Parentheses
Given a string containing just the characters '(' and ')', 
return the length of the longest valid (well-formed) parentheses substring.

*/




class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')' && !st.empty()) {
                v[i] = 1;
                v[st.top()] = 1;
                st.pop();
            }
        }
        int ans = 0;
        int ct = 0;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
            if (v[i] == 1)
                ct++;
            ans = max(ans, ct);
            if (v[i] == 0)
                ct = 0;
        }
        return ans;
    }
};