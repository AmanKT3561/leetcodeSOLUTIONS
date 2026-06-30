class Solution {
public:
    using ll = long long;

    const ll MOD = 1000000007;
    const ll BASE = 911382323;

    vector<int> rabinKarp(string &s, string &pat) {
        int n = s.size(), m = pat.size();
        vector<int> occ;
        if (m > n) return occ;

        ll power = 1;
        for (int i = 1; i < m; i++)
            power = (power * BASE) % MOD;

        ll patHash = 0;
        ll winHash = 0;

        for (int i = 0; i < m; i++) {
            patHash = (patHash * BASE + pat[i]) % MOD;
            winHash = (winHash * BASE + s[i]) % MOD;
        }

        if (patHash == winHash && s.substr(0, m) == pat)
            occ.push_back(0);

        for (int i = m; i < n; i++) {
            winHash =
                (winHash - (ll)s[i - m] * power % MOD + MOD) % MOD;
            winHash = (winHash * BASE + s[i]) % MOD;

            int start = i - m + 1;

            if (winHash == patHash)
                occ.push_back(start);
        }

        return occ;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {

        vector<int> posA = rabinKarp(s, a);
        vector<int> posB = rabinKarp(s, b);

        vector<int> ans;

        for (int x : posA) {

            auto it = lower_bound(posB.begin(), posB.end(), x);

            bool ok = false;

            if (it != posB.end() && abs(*it - x) <= k)
                ok = true;

            if (it != posB.begin()) {
                --it;
                if (abs(*it - x) <= k)
                    ok = true;
            }

            if (ok)
                ans.push_back(x);
        }

        return ans;
    }
};