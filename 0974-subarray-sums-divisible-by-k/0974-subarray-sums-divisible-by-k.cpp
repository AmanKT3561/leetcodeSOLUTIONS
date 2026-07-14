class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i : nums) {
            sum = (sum + i) % k;
            if (sum < 0)
                sum = sum + k; 
            count += mp[sum];
            mp[sum]++;
        }
        return count;
    }
};