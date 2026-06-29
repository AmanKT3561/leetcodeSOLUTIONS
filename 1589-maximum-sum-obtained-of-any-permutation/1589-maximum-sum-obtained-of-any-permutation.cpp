class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {

        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> diff(n + 1, 0);

        for (auto &q : requests) {
            diff[q[0]]++;
            if (q[1] + 1 < n)
                diff[q[1] + 1]--;
        }

        vector<long long> freq(n);

        freq[0] = diff[0];
        for (int i = 1; i < n; i++)
            freq[i] = freq[i - 1] + diff[i];

        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans = (ans + freq[i] * nums[i]) % MOD;
        }

        return ans;
    }
};