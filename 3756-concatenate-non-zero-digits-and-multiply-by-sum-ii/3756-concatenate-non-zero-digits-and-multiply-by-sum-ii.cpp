class Solution {
public:
    static constexpr int MOD = 1000000007;
    static constexpr int MX = 100001;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        static vector<long long> pow10 = []() {
            vector<long long> p(MX);
            p[0] = 1;
            for (int i = 1; i < MX; i++)
                p[i] = p[i - 1] * 10 % MOD;
            return p;
        }();

        int n = s.size();

        vector<int> sumD(n + 1), cntN0(n + 1);
        vector<long long> p(n + 1);

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';

            sumD[i] = sumD[i - 1] + d;
            cntN0[i] = cntN0[i - 1] + (d > 0);

            if (d)
                p[i] = (p[i - 1] * 10 + d) % MOD;
            else
                p[i] = p[i - 1];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int nonZero = cntN0[r + 1] - cntN0[l];
            int digitSum = sumD[r + 1] - sumD[l];

            long long x =
                (p[r + 1] - p[l] * pow10[nonZero] % MOD + MOD) % MOD;

            ans.push_back(x * digitSum % MOD);
        }

        return ans;
    }
};