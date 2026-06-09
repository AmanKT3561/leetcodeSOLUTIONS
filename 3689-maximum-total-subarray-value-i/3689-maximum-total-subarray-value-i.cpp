class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int a = *max_element(nums.begin(), nums.end());
        int y = *min_element(nums.begin(), nums.end());

        long long x = 1LL * a - y;
        long long ans = 1LL * k * x;

        return ans;
    }
};