class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int one=0,zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)zero++;
            else one++;
            int diff=zero-one;
            if(mp.count(diff))
                ans=max(ans,i-mp[diff]);
            else
                mp[diff]=i;
        } 
        return ans;
    }
};