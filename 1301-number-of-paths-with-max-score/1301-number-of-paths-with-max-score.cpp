class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
const long long NEG = -(1LL << 60);

int n = board.size();

vector<vector<pair<long long,int>>> dp(
    n, vector<pair<long long,int>>(n, {NEG, -1})
);

auto val = [&](int i, int j) {
    if (board[i][j] == 'S' || board[i][j] == 'E')
        return 0;
    return board[i][j] - '0';
};

auto dfs = [&](auto &&self, int i, int j) -> pair<long long,int> {

    if (i < 0 || j < 0 || board[i][j] == 'X')
        return {NEG, 0};

    if (i == 0 && j == 0)
        return {0, 1};

    if (dp[i][j].second != -1)
        return dp[i][j];

    auto [s1, c1] = self(self, i - 1, j);
    auto [s2, c2] = self(self, i, j - 1);
    auto [s3, c3] = self(self, i - 1, j - 1);

    long long best = max({s1, s2, s3});

    if (best == NEG)
        return dp[i][j] = {NEG, 0};

    long long ways = 0;
    if (s1 == best) ways = (ways + c1) % MOD;
    if (s2 == best) ways = (ways + c2) % MOD;
    if (s3 == best) ways = (ways + c3) % MOD;

    return dp[i][j] = {best + val(i, j), (int)ways};
};

auto [mx, cnt] = dfs(dfs, n - 1, n - 1);

if (cnt == 0) return {0, 0};
return {(int)mx, cnt};
    }
};