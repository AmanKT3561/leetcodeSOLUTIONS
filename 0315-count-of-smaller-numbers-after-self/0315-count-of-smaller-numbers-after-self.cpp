class Solution {
public:
    vector<int> seg;
    int size;

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            seg[node] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node + 1, l, mid);
        else
            update(idx, val, 2 * node + 2, mid + 1, r);

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    int query(int ql, int qr, int node, int l, int r) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return seg[node];

        int mid = (l + r) / 2;
        return query(ql, qr, 2 * node + 1, l, mid) +
               query(ql, qr, 2 * node + 2, mid + 1, r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        unordered_map<int, int> mp;
        for (int i = 0; i < temp.size(); i++) {
            mp[temp[i]] = i;
        }

        size = temp.size();
        seg.resize(4 * size, 0);

        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int idx = mp[nums[i]];

          
                ans[i] = query(0, idx - 1, 0, 0, size - 1);
            

            update(idx, 1, 0, 0, size - 1);
        }

        return ans;
    }
};