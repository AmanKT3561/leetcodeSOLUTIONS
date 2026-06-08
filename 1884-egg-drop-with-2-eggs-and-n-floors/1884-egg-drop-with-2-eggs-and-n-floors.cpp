class Solution {
public:
    int twoEggDrop(int n) {
        int ans = 0;
        while((ans*(ans+1))/2 < n){
            ans++;
        }
        return ans;
    }
};