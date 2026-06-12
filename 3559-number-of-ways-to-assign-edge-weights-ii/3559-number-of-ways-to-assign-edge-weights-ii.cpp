class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        map<int, vector<int>> adj;

        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int n = edges.size() + 1;
        vector<vector<int>> dp(n + 3, vector<int>(21, 0));
        vector<int> level(n + 1, 0);

        function<void(int, int, int)> dfs = [&](int node, int par, int x) {
            dp[node][0] = par;
            level[node] = x;
            for (int i = 1; i <= 17; i++) {
                dp[node][i] = dp[dp[node][i - 1]][i - 1];
            }
            for (auto i : adj[node]) {
                if (i == par)
                    continue;
                dfs(i, node, x + 1);
            }
        };
        dfs(1, 0, 0);
        auto func = [&](int k, int node) -> int {
            for (int i = 17; i >= 0; i--) {
                if ((k >> i) & 1)
                    node = dp[node][i];
            }
            return node;
        };

        int MOD = 1000000007;

        auto modPow = [&](int a, int b) -> int {
            long long res = 1;
            long long base = a;

            while (b) {
                if (b & 1)
                    res = res * base % MOD;
                base = base * base % MOD;
                b >>= 1;
            }

            return (int)res;
        };

        vector<int> res;

        for (auto l : queries) {
            int a = l[0];
            int b = l[1];
            int p = a, q = b;
            if (level[a] > level[b])
                swap(a, b);
            int k = level[b] - level[a];
            b = func(k, b);
            int lca;
            if (a == b) {
                lca = a;
            } else {
                for (int i = 17; i >= 0; i--) {
                    if (dp[a][i] != dp[b][i]) {
                        a = dp[a][i];
                        b = dp[b][i];
                    }
                }
                lca = dp[a][0];
            }
            int ans = level[p] - level[lca] + level[q] - level[lca];
            if(ans == 0){
    res.push_back(0);
    continue;
}
            int anss = modPow(2, ans - 1);
            res.push_back(anss);
        }

        return res;
    }
};