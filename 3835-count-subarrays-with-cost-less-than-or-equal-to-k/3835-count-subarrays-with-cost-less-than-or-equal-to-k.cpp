class SegmentTree_Max {
public:
    int n;
    vector<long long> tree;
    SegmentTree_Max(int n) : n(n) {
        tree.assign(4 * n, -1e18);
    }

    void build(const vector<long long> &a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(a, node * 2, start, mid);
        build(a, node * 2 + 1, mid + 1, end);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    long long query(int node, int start, int end, int l, int r) {
        if (l > r) return -1e18;
        if (l == start && r == end) return tree[node];
        int mid = (start + end) / 2;
        return max(
            query(node * 2, start, mid, l, min(r, mid)),
            query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r)
        );
    }
};

class SegmentTree_Min {
public:
    int n;
    vector<long long> tree;
    SegmentTree_Min(int n) : n(n) {
        tree.assign(4 * n, 1e18);
    }

    void build(const vector<long long> &a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(a, node * 2, start, mid);
        build(a, node * 2 + 1, mid + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    long long query(int node, int start, int end, int l, int r) {
        if (l > r) return 1e18;
        if (l == start && r == end) return tree[node];
        int mid = (start + end) / 2;
        return min(
            query(node * 2, start, mid, l, min(r, mid)),
            query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r)
        );
    }
};

class Solution {
public:
    
    long long countSubarrays(vector<int>& a, long long k) {
        vector<long long> b;
        for (int i : a) b.push_back(i);
        long long invalid = 0, n = a.size(), ans = 0, j = 0;

        SegmentTree_Max st1(n);
        SegmentTree_Min st2(n);
        st1.build(b, 1, 0, n - 1);
        st2.build(b, 1, 0, n - 1);

        for (int i = 0; i < n; i++) {
            while (true) {
                int curr_mx = st1.query(1, 0, n - 1, j, i);
                int curr_mn = st2.query(1, 0, n - 1, j, i);
                long long cost = curr_mx - curr_mn;
                cost *= (i - j + 1LL);
                if (cost > k) {
                    ++j;
                }
                else {
                    break;
                }
            }
            ans += (i - j + 1LL);
        }
        return ans;
    }
};