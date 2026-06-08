class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();

        const long long MOD = 1000000007LL;
        const long long BASE = 26LL;

        vector<long long> power(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * BASE) % MOD;
        }

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] =
                (pref[i] * BASE + (s[i] - 'a' + 1)) % MOD;
        }

        auto getHash = [&](int l, int r) {
            long long h =
                (pref[r + 1] -
                 pref[l] * power[r - l + 1] % MOD +
                 MOD) % MOD;
            return h;
        };

        int bestStart = -1;
        int bestLen = 0;

        auto check = [&](int len) -> int {
            unordered_map<long long, vector<int>> mp;

            for (int i = 0; i + len - 1 < n; i++) {
                long long h = getHash(i, i + len - 1);

                if (mp.count(h)) {
                    string cur = s.substr(i, len);

                    for (int start : mp[h]) {
                        if (s.compare(start, len, cur) == 0)
                            return i;
                    }
                }

                mp[h].push_back(i);
            }

            return -1;
        };

        int low = 1, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int pos = check(mid);

            if (pos != -1) {
                bestLen = mid;
                bestStart = pos;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return bestStart == -1 ? "" : s.substr(bestStart, bestLen);
    }
};