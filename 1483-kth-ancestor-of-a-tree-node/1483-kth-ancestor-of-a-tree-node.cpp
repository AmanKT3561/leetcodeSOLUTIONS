class TreeAncestor {
public:
    int N;
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        map<int, vector<int>> adj;

        dp.resize(n, vector<int>(32, -1));
        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        auto func = [&]() -> void {
            for (int i = 0; i < n; i++)
                dp[i][0] = parent[i];

            for (int i = 1; i < 32; i++) {
                for (int j = 0; j < n; j++) {
                    int p = dp[j][i - 1];
                    if (p != -1)
                        dp[j][i] = dp[p][i - 1];
                }
            }
        };

        func();
    }

    int getKthAncestor(int node, int k) {

        auto func = [&]() -> int {
            for (int i = 0; i < 32 && node != -1; i++) {

                if (k & (1 << i))
                    node = dp[node][i];
            }

            return node;
        };

        return func();
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */