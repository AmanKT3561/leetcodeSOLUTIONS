class Solution {
public:
    int minOperations(int n) {
        long long ans = 0;
        if (n % 2) {
            int x = n;
            while (n != 1) {
                n -= 2;
                ans += x - n;
            }
        } else {
            int x = n;
            n--;
            ans++;
            while (n != 1) {
                n -= 2;
                ans += x - n;
            }
        }
        return (int)ans;
    }
};