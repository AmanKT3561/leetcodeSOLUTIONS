#define ll long long int
const int N = 1e6 + 10;
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        ll par[2 * N];
        ll size[2 * N];
        ll ed[N + 1];
        auto make = [&](ll v) -> void {
            par[v] = v;
            size[v] = 1;
            ed[v] = 0;
        };

        for (int i = 0; i < n; i++) {
            make(i);
        }

        function<ll(ll)> find = [&](ll v) {
            if (v == par[v]) {
                return v;
            }
            return par[v] = find(par[v]);
        };

        auto unionn = [&](ll a, ll b) -> void {
            a = find(a);
            b = find(b);
            ed[a]++;
            if (a != b) {
                if (size[a] < size[b]) {
                    swap(a, b);
                }
                par[b] = a;
                ed[a] += ed[b];
                size[a] += size[b];
            }
        };

        for (auto it : edges) {
            unionn(it[0], it[1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                int node = size[i];
                int edge = ed[i];

                if (edge == (node * (node - 1)) / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};