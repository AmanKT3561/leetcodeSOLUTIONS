const int N = 1e5+1;
vector<vector<int>> in_edges (N);
vector<vector<int>> out_edges(N);

vector<int> down(N), up(N);

class Solution {
    
    void dfs_in (int src, int par) {
        int &result = down[src];

        for (auto i : out_edges[src]) {
            if (i == par) continue;
            
            dfs_in (i, src);
            result += down[i];
        }
        for (auto i : in_edges[src]) {
            if (i == par) continue;
            
            dfs_in (i, src);
            result += down[i] + 1;
        }
    }
    
    void dfs_out (int src, int par) {
        int all_child_sum = down[src];
        
        for (auto i : out_edges[src]) {
            if (i == par) continue;
            
            up[i] = up[src] + 1 + (all_child_sum - down[i]);
            dfs_out(i, src);
        }
        for (auto i : in_edges[src]) {
            if (i == par) continue;
            
            up[i] = up[src] + (all_child_sum - down[i] - 1);
            dfs_out(i, src);
        }
    }
    
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        for (int j = 0; j < N; j ++) {
            in_edges[j].clear();
            out_edges[j].clear();
            down[j] = up[j] = 0;
        }
        
        for (auto i : edges) {
            out_edges[i[0]].push_back(i[1]);
            in_edges [i[1]].push_back(i[0]);
        }
        dfs_in(0, -1);
        dfs_out(0, -1);
        
        // for (int j = 0; j < n; j ++) cout << down[j] << " "; cout << endl;
        // for (int j = 0; j < n; j ++) cout <<   up[j] << " "; cout << endl;
        
        vector<int> result(n);
        for (int j = 0; j < n; j ++) 
            result[j] = down[j] + up[j];
        return result;
    }
};