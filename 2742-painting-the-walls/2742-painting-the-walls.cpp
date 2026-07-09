class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {

        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        auto solve = [&](auto &&self, int idx, int remain) -> int {

            if (remain <= 0)
                return 0;

            if (idx == n)
                return 1e9;

            int &memo = dp[idx][remain];
            if (memo != -1)
                return memo;

            int take = cost[idx] +
                       self(self, idx + 1,
                            max(0, remain - time[idx] - 1));

            int skip = self(self, idx + 1, remain);

            return memo = min(take, skip);
        };

        return solve(solve, 0, n);
    }
};