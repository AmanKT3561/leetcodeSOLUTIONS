class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;

        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> up(m, 1), down(m, 1);
        vector<long long> nup(m), ndown(m);

        for (int len = n; len >= 3; len--) {

            vector<long long> prefUp(m + 1, 0);
            vector<long long> prefDown(m + 1, 0);

            for (int i = 0; i < m; i++) {
                prefUp[i + 1] = (prefUp[i] + up[i]) % MOD;
                prefDown[i + 1] = (prefDown[i] + down[i]) % MOD;
            }

            for (int i = 0; i < m; i++) {

                nup[i] = (prefDown[m] - prefDown[i + 1] + MOD) % MOD;

                ndown[i] = prefUp[i];
            }

            swap(up, nup);
            swap(down, ndown);
        }

        vector<long long> prefUp(m + 1, 0);
        vector<long long> prefDown(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefUp[i + 1] = (prefUp[i] + up[i]) % MOD;
            prefDown[i + 1] = (prefDown[i] + down[i]) % MOD;
        }

        long long ans = 0;

        for (int first = 0; first < m; first++) {

            long long inc =
                (prefDown[m] - prefDown[first + 1] + MOD) % MOD;

            long long dec =
                prefUp[first];

            ans = (ans + inc + dec) % MOD;
        }

        return (int)ans;
    }
};