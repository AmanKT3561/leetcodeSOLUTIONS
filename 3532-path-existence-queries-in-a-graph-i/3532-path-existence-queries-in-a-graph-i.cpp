class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int cnt = 0;
        map<int,int> mp;
        vector<bool> ans;
        mp[0] = cnt;
        for(int i = 1 ; i<nums.size() ; i++){
        if(nums[i] - nums[i-1] <= maxDiff) mp[i] = cnt;
        else{
          cnt++;
          mp[i] = cnt;
        }
        }

        for(auto i:queries){
          if(mp[i[0]] == mp[i[1]]) ans.push_back(1);
          else ans.push_back(0);
        }
    return ans;
    }
};