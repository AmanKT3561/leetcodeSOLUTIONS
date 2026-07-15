class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, long long> mp;

        mp[0] = 1;

        long long ans = 0;
        int prefixXor = 0;

        for (int x : nums) {
            prefixXor ^= x;
            ans += mp[prefixXor];
            mp[prefixXor]++;
        }

        return ans;
    }
};