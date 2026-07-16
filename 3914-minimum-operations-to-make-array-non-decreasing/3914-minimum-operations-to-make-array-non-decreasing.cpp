class Solution {
public:
    long long minOperations(vector<int>& nums) {
     long long ans = 0;
     int n = nums.size();

     for(int i = 1 ; i < n ; i++){
     ans = ans + (nums[i-1] > nums[i] ? nums[i-1] - nums[i] : 0);
     }      
     return ans;
    }
};