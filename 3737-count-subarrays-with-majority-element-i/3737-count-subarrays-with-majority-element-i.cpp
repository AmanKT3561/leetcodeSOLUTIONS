class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
      int cnt = 0;
      int n = nums.size();
        for(int i = 0 ; i< n ; i++)
          {
            unordered_map<int,int> mp;
            for(int j = i ; j < n ; j++)
              {
                  mp[nums[j]]++;
                  if(mp[target] > (j-i+1) / 2) cnt++;
              }
            
          }
      return cnt;
    }
};