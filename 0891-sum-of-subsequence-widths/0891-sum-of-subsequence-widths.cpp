class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<long long> pow2(n);
        pow2[0] = 1;

        for (int i = 1; i < n; i++)
            pow2[i] = (pow2[i - 1] * 2) % mod;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long mx = pow2[i];
            long long mn = pow2[n - i - 1];

            ans = (ans + nums[i] * (mx - mn)) % mod;
        }

        return (ans + mod) % mod;
    }
};