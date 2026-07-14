class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
         int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                dp[r + 1][c + 1] =
                    matrix[r][c] + dp[r][c + 1] + dp[r + 1][c] - dp[r][c];
            }
        }

        int count = 0;
        int ans = INT_MIN;

        for (int sR = 0; sR < m; sR++) {
            for (int sC = 0; sC < n; sC++) {
                for (int eR = sR; eR < m; eR++) {
                    for (int eC = sC; eC < n; eC++) {

                        int sum = dp[eR + 1][eC + 1] + dp[sR][sC] -
                                  dp[eR + 1][sC] - dp[sR][eC + 1];

                        if (sum <= k)
                            ans = max(ans , sum);
                    }
                }
            }
        }

        return ans;
    }
};