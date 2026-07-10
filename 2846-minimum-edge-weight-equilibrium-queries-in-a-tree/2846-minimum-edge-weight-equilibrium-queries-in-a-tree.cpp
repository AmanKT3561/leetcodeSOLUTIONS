class Tree {
public:
    vector<int> euler;
    vector<int> depthEuler;
    vector<int> first;
    vector<int> seg;
    vector<int> depth;
    vector<int>* adj;

    Tree(vector<int>* g, int n) {
        adj = g;
        first.assign(n, -1);
        depth.assign(n, 0);

        dfs(0, -1, 0);

        seg.resize(4 * euler.size());
        build(1, 0, euler.size() - 1);
    }

    void dfs(int node, int par, int d) {
        depth[node] = d;

        if (first[node] == -1)
            first[node] = euler.size();

        euler.push_back(node);
        depthEuler.push_back(d);

        for (int child : adj[node]) {
            if (child == par) continue;
            dfs(child, node, d + 1);
            euler.push_back(node);
            depthEuler.push_back(d);
        }
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = l;
            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);

        if (depthEuler[seg[idx * 2]] < depthEuler[seg[idx * 2 + 1]])
            seg[idx] = seg[idx * 2];
        else
            seg[idx] = seg[idx * 2 + 1];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (r < ql || l > qr)
            return -1;

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        int left = query(idx * 2, l, mid, ql, qr);
        int right = query(idx * 2 + 1, mid + 1, r, ql, qr);

        if (left == -1) return right;
        if (right == -1) return left;

        if (depthEuler[left] < depthEuler[right])
            return left;
        return right;
    }

    int lca(int u, int v) {
        int l = first[u];
        int r = first[v];

        if (l > r)
            swap(l, r);

        int idx = query(1, 0, euler.size() - 1, l, r);

        return euler[idx];
    }
};


class Solution {
public:

int dp[10000][27];
vector<int>g[10000];
int height[10000];
vector<int>res;
vector<pair<int,int>>gw[10000];

void dfs(int node,int p){
    for(auto &c:gw[node]){
        int child=c.first;
        int wt=c.second;

        if(child != p){
            height[child]=height[node]+1;
            for(int j=1;j<=26;j++){
                dp[child][j]=dp[node][j];
            }
            dp[child][wt] += 1;
            dfs(child,node);
        }
    }
}

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for(auto &c:edges){
            int u=c[0];
            int v=c[1];
            int w=c[2];
            g[u].push_back(v);
            g[v].push_back(u);
            
            gw[u].push_back({v,w});
            gw[v].push_back({u,w});
        }

        Tree tree(g,n);
        dfs(0,-1);

        for(auto &c:queries){
            int ai=c[0];
            int bi=c[1];

            int lcaOfAiandBi=tree.lca(ai,bi);

            int totalEdgesBwAiandBi= height[ai] + height[bi] - 2*(height[lcaOfAiandBi]);

            int maxi=0;
            for(int j=1;j<=26;j++){
                int freq=dp[ai][j] + dp[bi][j] - 2*(dp[lcaOfAiandBi][j]);
                maxi=max(maxi,freq);
            }

            res.push_back(totalEdgesBwAiandBi - maxi);
        }

        return res;
    }
};