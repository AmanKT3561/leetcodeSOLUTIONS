class Solution {
    vector<int> digits;
    vector<int> ans;
    int l = 0;

    void dfs(int pos, bool tight, bool started, int prev, int num) {
        if (pos == digits.size()) {
            if (started && num >= l)
                ans.push_back(num);
            return;
        }

        int limit = tight ? digits[pos] : 9;

        if (!started) {
            dfs(pos + 1, tight && (0 == digits[pos]), false, 0, 0);

            for (int d = 1; d <= limit; d++) {
                dfs(pos + 1, tight && (d == digits[pos]), true, d, d);
            }
        } else {
            if (prev == 9)
                return;

            int nxt = prev + 1;

            if (nxt <= limit) {
                dfs(pos + 1, tight && (nxt == digits[pos]), true, nxt,
                    num * 10 + nxt);
            }
        }
    }

    void digit(int x) {
        digits.clear();

        if (x == 0)
            digits.push_back(0);

        while (x) {
            digits.push_back(x % 10);
            x /= 10;
        }

        reverse(digits.begin(), digits.end());

        dfs(0, true, false, 0, 0);
    }

public:
    vector<int> sequentialDigits(int low, int high) {
        l = low;
        ans.clear();
        digit(high);
        sort(ans.begin(), ans.end());
        return ans;
    }
};