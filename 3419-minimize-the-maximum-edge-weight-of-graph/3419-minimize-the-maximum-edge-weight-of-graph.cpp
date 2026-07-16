class Solution {
public:
    bool check(int mid, int n, vector<vector<int>>& edges) {
        vector<vector<int>> rev(n);

        for (auto &e : edges) {
            if (e[2] <= mid) {
                rev[e[1]].push_back(e[0]);   
            }
        }

        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : rev[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) return false;
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {

        int lo = 1, hi = 0;

        for (auto &e : edges)
            hi = max(hi, e[2]);

        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid, n, edges)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};