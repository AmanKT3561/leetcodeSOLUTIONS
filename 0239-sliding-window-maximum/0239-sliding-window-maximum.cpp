class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> seg(4 * n);

        auto build = [&](auto &&self, int node, int l, int r) -> void {
            if (l == r) {
                seg[node] = nums[l];
                return;
            }

            int mid = (l + r) / 2;

            self(self, 2 * node, l, mid);
            self(self, 2 * node + 1, mid + 1, r);

            seg[node] = max(seg[2 * node], seg[2 * node + 1]);
        };

        auto query = [&](auto &&self, int node, int l, int r,
                         int ql, int qr) -> int {

            if (r < ql || l > qr)
                return INT_MIN;

            if (ql <= l && r <= qr)
                return seg[node];

            int mid = (l + r) / 2;

            return max(
                self(self, 2 * node, l, mid, ql, qr),
                self(self, 2 * node + 1, mid + 1, r, ql, qr)
            );
        };

        build(build, 1, 0, n - 1);

        vector<int> ans;

        for (int l = 0, r = k - 1; r < n; l++, r++) {
            ans.push_back(query(query, 1, 0, n - 1, l, r));
        }

        return ans;
    }
};