class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        map<int, vector<int>> adj;
        int n = quiet.size();
        vector<int> indeg(n, 0);
        for (auto i : richer) {
            adj[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indeg[i] == 0)
                q.push(i);
        vector<set<pair<int, int>>> st(n);
        for (int i = 0; i < n; i++)
            st[i].insert({quiet[i], i});
        while (!q.empty()) {
            auto x = q.front();
            q.pop();

            for (auto i : adj[x]) {
                for (auto j : st[x]) {
                    st[i].insert(j);
                }
                st[i].insert({quiet[x], x});
                indeg[i]--;
                if (indeg[i] == 0)
                    q.push(i);
            }
        }
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (st[i].empty())
                ans.push_back(i);
            else
                ans.push_back(st[i].begin()->second);
        }
        return ans;
    }
};