class Solution {
    class DSU {
    public:
        vector<int> Parent, Rank;

        DSU(int n) {
            Parent.resize(n);
            Rank.resize(n, 0);
            for (int i = 0; i < n; i++) Parent[i] = i;
        }

        int Find(int x) {
            return Parent[x] = (Parent[x] == x ? x : Find(Parent[x])); 
        }

        bool Union(int x, int y) {
            int xset = Find(x), yset = Find(y);
            if (xset != yset) {
                if (Rank[xset] < Rank[yset]) Parent[xset] = yset;
                else if (Rank[xset] > Rank[yset]) Parent[yset] = xset;
                else {
                    Parent[yset] = xset;
                    Rank[xset]++;
                }
                return true;
            }
            return false;
        }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for (auto edge : edges) {
            if (!dsu.Union(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return {};
    }
};