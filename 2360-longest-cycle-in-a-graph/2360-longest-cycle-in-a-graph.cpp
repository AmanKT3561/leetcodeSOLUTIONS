class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> check(n, 0);
        vector<int> dist(n, 1);
        vector<bool> visited(n, 0);

        int ans = -1;

        function<void(int)> func = [&](int node) {
            if (node != -1) {
                check[node] = 1;

                int res = edges[node];

                visited[node] = 1;

                if (res != -1 && !visited[res]) {
                    dist[res] = dist[node] + 1;
                    func(res);
                } else if (res != -1 && check[res]) {
                    ans = max(ans, dist[node] - dist[res] + 1);
                }

                check[node] = 0;
            }
        };

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                func(i);
        }
        return ans;
    }
};