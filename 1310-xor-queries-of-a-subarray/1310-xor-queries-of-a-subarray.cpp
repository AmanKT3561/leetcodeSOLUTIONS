class SegmentTree {
        vector<int> seg;
        int n;

        void build(vector<int>& arr, int idx, int low, int high) {
            if (low == high) {
                seg[idx] = arr[low];
                return;
            }
            int mid = (low + high) / 2;
            build(arr, 2 * idx + 1, low, mid);
            build(arr, 2 * idx + 2, mid + 1, high);
            seg[idx] = (seg[2 * idx + 1] ^ seg[2 * idx + 2]);
        }

        int queryUtil(int idx, int low, int high, int l, int r) {
            if (r < low || high < l)
                return 0; // no overlap
            if (l <= low && high <= r)
                return seg[idx]; // total overlap
            int mid = (low + high) / 2;
            int left = queryUtil(2 * idx + 1, low, mid, l, r);
            int right = queryUtil(2 * idx + 2, mid + 1, high, l, r);
            return (left ^ right);
        }

        void updateUtil(int idx, int low, int high, int pos, int val) {
            if (low == high) {
                seg[idx] = val;
                return;
            }
            int mid = (low + high) / 2;
            if (pos <= mid)
                updateUtil(2 * idx + 1, low, mid, pos, val);
            else
                updateUtil(2 * idx + 2, mid + 1, high, pos, val);
            seg[idx] = (seg[2 * idx + 1] ^ seg[2 * idx + 2]);
        }

    public:
        SegmentTree(vector<int>& arr) {
            n = arr.size();
            seg.assign(4 * n, 0);
            build(arr, 0, 0, n - 1);
        }

        int query(int l, int r) { return queryUtil(0, 0, n - 1, l, r); }

        void update(int pos, int val) { updateUtil(0, 0, n - 1, pos, val); }
    };


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        SegmentTree st(arr);
        vector<int> ans;
        for (auto i : queries) {
            int l = i[0];
            int r = i[1];

            int x = st.query(l, r);
            ans.push_back(x);
        }
        return ans;
    }
    };