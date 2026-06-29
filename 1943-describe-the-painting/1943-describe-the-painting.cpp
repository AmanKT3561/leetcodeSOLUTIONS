class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {

        map<int,long long> mp;

        for(auto &v: segments){
            mp[v[0]] += v[2];
            mp[v[1]] -= v[2];
        }

        vector<vector<long long>> ans;

        long long sum = 0;
        int prev = -1;

        for(auto &[x, delta] : mp){

            if(prev != -1 && sum > 0){
                ans.push_back({(long long)prev, (long long)x, sum});
            }

            sum += delta;
            prev = x;
        }

        return ans;
    }
};