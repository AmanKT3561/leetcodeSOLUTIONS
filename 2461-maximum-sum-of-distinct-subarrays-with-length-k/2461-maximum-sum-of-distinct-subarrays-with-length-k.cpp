class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        long long ans = 0;

        vector<long long> pref(n);

        pref[0] = nums[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + nums[i];

        auto func = [&]() -> void {
            int l = 0;
            int r = 0;
            unordered_map<int, int> mp;

            while (r < n && l < n) {
                mp[nums[r]]++;

                if (mp[nums[r]] > 1) {
                    while (mp[nums[r]] != 1) {
                        mp[nums[l]]--;
                        l++;
                    }
                }

                while (r - l + 1 > k) {
                    mp[nums[l]]--;
                    if (mp[nums[l]] == 0)
                        mp.erase(nums[l]);
                    l++;
                }

                if (r - l + 1 == k) {
                    long long sum = pref[r];
                    if (l > 0)
                        sum -= pref[l - 1];

                    ans = max(ans, sum);
                }

                r++;
            }
        };

        func();
        return ans;
    }
};