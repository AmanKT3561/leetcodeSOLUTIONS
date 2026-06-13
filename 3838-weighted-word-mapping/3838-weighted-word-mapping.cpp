class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& w) {
        string ans = "";
        map<char, int> mp;
        int val = 0;
        for (char c = 'z'; c >= 'a'; c--) {
            mp[val++] = c;
        }
        for (auto i : words) {
            string s = i;
            int sum = 0;
            for (auto j : s) {
                sum += w[j - 'a'];
            }
            sum %= 26;
            ans+=mp[sum];
        }
      return ans;
    }
};