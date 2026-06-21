class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        const long long MOD = 1e9 + 7;

        auto count = [&](long long x) {
            long long total = 0;

            for (int i = 0; i < value.size(); i++) {
                long long v = value[i];
                long long d = decay[i];

                if (v >= x) {
                    total += (v - x) / d + 1;
                }
            }

            return total;
        };

        auto getSum = [&](long long x) {
            long long total = 0;

            for (int i = 0; i < value.size(); i++) {
                long long v = value[i];
                long long d = decay[i];

                if (v >= x) {
                    long long c = (v - x) / d + 1;
                    total += c * (2 * v - (c - 1) * d) / 2;
                }
            }

            return total;
        };

        long long positive = count(1);

        if (positive <= m) {
            return getSum(1) % MOD;
        }

        long long left = 1;
        long long right = *max_element(value.begin(), value.end());

        while (left < right) {
            long long mid = (left + right + 1) / 2;

            if (count(mid) >= m)
                left = mid;
            else
                right = mid - 1;
        }

        long long f = left;
        long long cnt = count(f + 1);
        long long sum = getSum(f + 1);

        long long rem = m - cnt;
        long long ans = sum + rem * f;

        return ans % MOD;
    }
};