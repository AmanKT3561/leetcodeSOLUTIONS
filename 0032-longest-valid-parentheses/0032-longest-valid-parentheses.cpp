class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;

        for (auto i : s) {
            if (i == '(')
                l++;
            else
                r++;

            if (l == r)
                ans = max(ans, l + r);
            if (r > l) {
                l = 0;
                r = 0;
            }
        }
        l = 0 ; r= 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')')
                r++;
            else
                l++;
            if (l == r)
                ans = max(ans, l + r);
            if (l > r) {
                l = 0;
                r = 0;
            }
        }
        return ans;
    }
};