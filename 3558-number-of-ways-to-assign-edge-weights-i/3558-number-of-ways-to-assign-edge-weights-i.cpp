class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {

        map<int, vector<int>> adj;
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int maxDepth = 0;

        auto dfs = [&](auto&& self, int node, int parent, int depth) -> void {
            maxDepth = max(maxDepth, depth);

            for (int child : adj[node]) {
                if (child == parent)
                    continue;
                self(self, child, node, depth + 1);
            }
        };

        dfs(dfs, 1, -1, 0);;
        const int MOD = 1e9 + 7;

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

         int ans = modPow(2, maxDepth - 1); 
         return ans;
    }
};